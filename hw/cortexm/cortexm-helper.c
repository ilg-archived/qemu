/*
 * Cortex-M devices emulation helper.
 *
 * Copyright (c) 2015 Liviu Ionescu.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include "hw/arm/cortexm-helper.h"
#include "hw/arm/cortexm-mcu.h"

#include "hw/boards.h"
#include "qom/object.h"
#include "cpu-qom.h"
#include "qemu/error-report.h"
#include "qapi/visitor.h"

#include "sysemu/sysemu.h"
#if defined(CONFIG_SDL)
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#endif

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

/* ------------------------------------------------------------------------- */

/**
 * When verbose, display a line to identify the board (name, description).
 *
 * Does not really depend on Cortex-M, but I could not find a better place.
 */
void cm_board_greeting(MachineState *machine)
{
#if defined(CONFIG_VERBOSE)
    if (verbosity_level >= VERBOSITY_COMMON) {
        MachineClass *mc = MACHINE_GET_CLASS(machine);
        printf("Board: '%s' (%s).\n", mc->name, mc->desc);
    }
#endif
}

/* ------------------------------------------------------------------------- */

static QEMUTimer *timer;

/**
 * SDL event loop, called every 10 ms by the timer.
 */
static void sdl_event_loop(void *p)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        //If the user has Xed out the window
        if (event.type == SDL_QUIT) {
            //Quit the program
            fprintf(stderr, "Quit.\n");
            exit(1);
        }
    }

    timer_mod(timer, qemu_clock_get_ms(QEMU_CLOCK_REALTIME) + 10);
}

/**
 * Initialise SDL and display the board image.
 */
void *cm_board_init_image(const char *file_name, const char *caption)
{
    void *board_surface = NULL;
#if defined(CONFIG_SDL)
    if (display_type != DT_NOGRAPHIC) {
        // Start SDL, if needed.
        if (SDL_WasInit(SDL_INIT_VIDEO) == 0) {
            SDL_Init(SDL_INIT_VIDEO);
        }

        const char *fullname = qemu_find_file(QEMU_FILE_TYPE_IMAGES, file_name);
        if (fullname == NULL) {
            error_printf("Image file '%s' not found.\n", file_name);
            exit(1);
        }

        int res = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
        if ((res & (IMG_INIT_JPG | IMG_INIT_PNG))
                != (IMG_INIT_JPG | IMG_INIT_PNG)) {
            error_printf("IMG_init failed (%s).\n", IMG_GetError());
            exit(1);
        }
        /* A better SDL_LoadBMP(). */
        SDL_Surface* board_bitmap = IMG_Load(fullname);
        if (board_bitmap == NULL) {
            error_printf("Cannot load image file '%s' (%s).\n", fullname,
                    IMG_GetError());
            exit(1);
        }

#if defined(CONFIG_VERBOSE)
        if (verbosity_level >= VERBOSITY_DETAILED) {
            printf("Board picture: '%s'.\n", fullname);
        }
#endif

        SDL_WM_SetCaption(caption, NULL);
        SDL_Surface* screen = SDL_SetVideoMode(board_bitmap->w, board_bitmap->h,
                32, SDL_DOUBLEBUF);

        SDL_Surface* board = SDL_DisplayFormat(board_bitmap);
        SDL_FreeSurface(board_bitmap);

        /* Apply image to screen */
        SDL_BlitSurface(board, NULL, screen, NULL);
        /* Update screen */
        SDL_Flip(screen);
        board_surface = screen;

        /* The event loop will be processed from time to time. */
        timer = timer_new_ms(QEMU_CLOCK_REALTIME, sdl_event_loop, &timer);
        timer_mod(timer, qemu_clock_get_ms(QEMU_CLOCK_REALTIME));
    }

#endif
    return board_surface;
}

static void cm_mcu_help_foreach(gpointer data, gpointer user_data)
{
    ObjectClass *oc = data;
    const char *typename;

    typename = object_class_get_name(oc);
    printf("  %s\n", typename);
}

static gint object_class_cmp(gconstpointer a, gconstpointer b)
{
    return strcmp(object_class_get_name(OBJECT_CLASS(a)),
            object_class_get_name(OBJECT_CLASS(b)));
}

bool cm_mcu_help_func(const char *mcu_device)
{

    if ((mcu_device == NULL) || !is_help_option(mcu_device)) {
        return false;
    }

    GSList *list;

    list = object_class_get_list(TYPE_CORTEXM_MCU, false);
    list = g_slist_sort(list, object_class_cmp);

    printf("\nSupported MCUs:\n");
    g_slist_foreach(list, cm_mcu_help_foreach, NULL);
    g_slist_free(list);

    return true;
}

bool cm_board_help_func(const char *name)
{
    if ((name == NULL) || !is_help_option(name)) {
        return false;
    }

    printf("\nSupported boards:\n");

    GSList *el, *machines = object_class_get_list(TYPE_MACHINE, false);

    machines = g_slist_sort(machines, object_class_cmp);
    for (el = machines; el; el = el->next) {
        MachineClass *mc = el->data;
        if (mc->alias) {
            printf("  %-20s %s (alias of %s)\n", mc->alias, mc->desc, mc->name);
        }
        printf("  %-20s %s%s\n", mc->name, mc->desc,
                mc->is_default ? " (default)" : "");
    }

    return true;
}

const char *cm_board_get_name(MachineState *machine)
{
    return object_class_get_name(OBJECT_CLASS(machine));
}

const char *cm_board_get_desc(MachineState *machine)
{
    return MACHINE_GET_CLASS(machine)->desc;
}

/* ------------------------------------------------------------------------- */

/**
 * A version of cpu_generic_init() that does only the object creation and
 * initialisation, without calling realize().
 */
static CPUState *cm_cpu_generic_create(const char *typename,
        const char *cpu_model)
{
    char *str, *name, *featurestr;
    CPUState *cpu;
    ObjectClass *oc;
    CPUClass *cc;
    Error *err = NULL;

    str = g_strdup(cpu_model);
    name = strtok(str, ",");

    oc = cpu_class_by_name(typename, name);
    if (oc == NULL) {
        g_free(str);
        return NULL;
    }

    cpu = CPU(object_new(object_class_get_name(oc)));
    cc = CPU_GET_CLASS(cpu);

    featurestr = strtok(NULL, ",");
    cc->parse_features(cpu, featurestr, &err);
    g_free(str);
    if (err != NULL) {
        error_report_err(err);
        object_unref(OBJECT(cpu));
        return NULL;
    }

    return cpu;
}

/**
 * A version of cpu_arm_init() that does only the object creation and
 * initialisation, without calling realize().
 */
void *cm_cpu_arm_create(Object *parent, const char *cpu_model)
{
    ARMCPU *cpu;
    cpu = (ARMCPU*) ARM_CPU(cm_cpu_generic_create(TYPE_ARM_CPU, cpu_model));
    if (!cpu) {
        error_report("Unable to find CPU definition %s", cpu_model);
        exit(1);
    }
    cm_object_property_add_child(parent, "core", OBJECT(cpu));

    return cpu;
}

/* ------------------------------------------------------------------------- */

Object *cm_object_get_parent(Object *obj)
{
    return obj->parent;
}

/**
 * Return true if the node is of given type. Go up the class hierarchy.
 */
bool cm_object_is_instance_of_typename(Object *obj, const char *type_name)
{
    ObjectClass *klass = object_get_class(obj);
    for (; klass;) {
        const char *name = object_class_get_name(klass);

        if (strcmp(type_name, name) == 0) {
            return true;
        }
        klass = object_class_get_parent(klass);
    }

    return false;
}

typedef struct {
    Object *parent;
    Object *child;
    const char *name;
} GetChildByNameTmp;

static int cm_object_get_child_by_name_foreach(Object *child, void *opaque)
{
    GetChildByNameTmp *p = (GetChildByNameTmp*) opaque;

    p->child = object_resolve_path_component(p->parent, p->name);
    if (p->child) {
        return 1;
    }
    return 0;
}

Object *cm_object_get_child_by_name(Object *obj, const char *name)
{
    GetChildByNameTmp tmp;
    tmp.parent = obj;
    tmp.name = name;
    tmp.child = NULL;
    int ret = object_child_foreach(obj, cm_object_get_child_by_name_foreach,
            (void *) &tmp);
    if (ret == 0) {
        error_report("Unable to find child %s", name);
        exit(1);
    }

    return tmp.child;
}

/* ------------------------------------------------------------------------- */

/**
 *  Realize object. Errors are fatal.
 *  Similar to qdev_init_nofail(), but with a less-confusing name, since
 *  qdev_init_nofail not only that it does not call init(), but realize(),
 *  and it may fail, and when it does it exits.
 */
void cm_object_realize(Object *obj)
{
    Error *err = NULL;

    object_property_set_bool(obj, true, "realized", &err);
    if (err) {
        error_report("Realization of object %s failed: %s",
                object_get_typename(obj), error_get_pretty(err));
        exit(1);
    }
}

Object *cm_object_new(Object *parent, const char* node_name,
        const char *type_name)
{
    if (object_class_by_name(type_name) == NULL) {
        error_report("Creating object of type %s failed; no such type.",
                type_name);
        exit(1);
    }

    Object *obj = object_new(type_name);
    if (!obj) {
        error_report("Creating object of type %s failed.", type_name);
        exit(1);
    }

    cm_object_property_add_child(parent, node_name, obj);
    return obj;
}

Object *cm_object_new_mcu(MachineState *machine, const char *board_device_name)
{
    const char *device_name = board_device_name;
    if (machine && machine->mcu_device) {
        device_name = machine->mcu_device;
    }

    return cm_object_new(cm_object_get_machine(), "mcu", device_name);
}

/**
 * Reset the device, if it exists.
 */
void cm_device_reset(DeviceState *dev)
{
    if (dev != NULL) {
        device_reset(dev);
    }
}

/**
 *  Call the parent realize() of a given type.
 */
bool cm_device_parent_realize(DeviceState *dev, Error **errp,
        const char *type_name)
{
    /* Identify parent class. */
    DeviceClass *klass = DEVICE_CLASS(
            object_class_get_parent(object_class_by_name(type_name)));

    if (klass->realize) {
        Error *local_err = NULL;
        klass->realize(dev, &local_err);
        if (local_err) {
            error_propagate(errp, local_err);
            return false;
        }
    }
    return true;
}

/**
 *  Call the realize() of a given type.
 */
bool cm_device_by_name_realize(DeviceState *dev, Error **errp,
        const char *type_name)
{
    /* Identify class. */
    DeviceClass *klass = DEVICE_CLASS(object_class_by_name(type_name));

    if (klass->realize) {
        Error *local_err = NULL;
        klass->realize(dev, &local_err);
        if (local_err) {
            error_propagate(errp, local_err);
            return false;
        }
    }
    return true;
}

/**
 * Call the parent reset() of a given type.
 */
void cm_device_parent_reset(DeviceState *dev, const char *type_name)
{
    /* Identify parent class. */
    DeviceClass *klass = DEVICE_CLASS(
            object_class_get_parent(object_class_by_name(type_name)));

    if (klass->reset) {
        klass->reset(dev);
    }
}

/**
 * Call the reset() of a given type.
 */
void cm_device_by_name_reset(DeviceState *dev, const char *type_name)
{
    /* Identify class. */
    DeviceClass *klass = DEVICE_CLASS(object_class_by_name(type_name));

    if (klass->reset) {
        klass->reset(dev);
    }
}

Object *cm_object_get_machine(void)
{
    static Object *obj;

    if (obj == NULL) {
        obj = container_get(object_get_root(), "/machine");
    }

    return obj;
}

void cm_object_property_set_int(Object *obj, int64_t value, const char *name)
{
    Error *err = NULL;
    object_property_set_int(obj, value, name, &err);
    if (err) {
        error_report("Setting int property %s for %s failed: %s.", name,
                object_get_typename(obj), error_get_pretty(err));
        exit(1);
    }
}

void cm_object_property_set_bool(Object *obj, bool value, const char *name)
{
    Error *err = NULL;
    object_property_set_bool(obj, value, name, &err);
    if (err) {
        error_report("Setting bool property %s for %s failed: %s.", name,
                object_get_typename(obj), error_get_pretty(err));
        exit(1);
    }
}

void cm_object_property_set_str(Object *obj, const char *value,
        const char *name)
{
    assert(obj);
    if (value == NULL) {
        return;
    }

    Error *err = NULL;
    object_property_set_str(obj, value, name, &err);
    if (err) {
        error_report("Setting string property %s for %s failed: %s.", name,
                object_get_typename(obj), error_get_pretty(err));
        exit(1);
    }
}

void cm_object_property_add_child(Object *obj, const char *node_name,
        Object *child)
{
    Error *err = NULL;
    object_property_add_child(obj, node_name, child, &err);
    if (err) {
        error_report("Adding child %s for %s failed: %s.", node_name,
                object_get_typename(obj), error_get_pretty(err));
        exit(1);
    }
}

Object *cm_container_get_peripheral(void)
{
    return container_get(object_get_root(), "/peripheral");
}

/* ------------------------------------------------------------------------- */

static void cm_property_get_str(Object *obj, Visitor *v, void *opaque,
        const char *name, Error **errp)
{
    char *value = *(char **) opaque;
    visit_type_str(v, &value, name, errp);
}

static void cm_property_set_str(Object *obj, Visitor *v, void *opaque,
        const char *name, Error **errp)
{
    Error *local_err = NULL;
    char *value;
    visit_type_str(v, &value, name, &local_err);
    if (!local_err) {
        *((char **) opaque) = value;
    }
    error_propagate(errp, local_err);
}

void cm_object_property_add_str(Object *obj, const char *name, char **v)
{
    Error *local_err = NULL;
    object_property_add(obj, name, "string", cm_property_get_str,
            cm_property_set_str,
            NULL, (void *) v, &local_err);
    if (local_err) {
        error_report("Adding property %s for %s failed: %s.", name,
                object_get_typename(obj), error_get_pretty(local_err));
        exit(1);
    }
}

void cm_object_property_add_const_str(Object *obj, const char *name,
        const char **v)
{
    Error *local_err = NULL;
    object_property_add(obj, name, "string", cm_property_get_str,
            cm_property_set_str,
            NULL, (void *) v, &local_err);
    if (local_err) {
        error_report("Adding property %s for %s failed: %s.", name,
                object_get_typename(obj), error_get_pretty(local_err));
        exit(1);
    }
}

static void cm_property_get_bool(Object *obj, Visitor *v, void *opaque,
        const char *name, Error **errp)
{
    bool value = *(bool *) opaque;
    visit_type_bool(v, &value, name, errp);
}

static void cm_property_set_bool(Object *obj, Visitor *v, void *opaque,
        const char *name, Error **errp)
{
    Error *local_err = NULL;
    bool value;

    visit_type_bool(v, &value, name, &local_err);
    if (!local_err) {
        *((bool *) opaque) = value;
    }
    error_propagate(errp, local_err);
}

ObjectProperty *
cm_object_property_add(Object *obj, const char *name, const char *type,
        ObjectPropertyAccessor *get, ObjectPropertyAccessor *set,
        ObjectPropertyRelease *release, void *opaque)
{
    Error *local_err = NULL;
    ObjectProperty *prop;
    prop = object_property_add(obj, name, type, get, set, release, opaque,
            &local_err);
    if (local_err) {
        error_report("Adding property %s for %s failed: %s.", name,
                object_get_typename(obj), error_get_pretty(local_err));
        exit(1);
    }

    return prop;
}

void cm_object_property_add_bool(Object *obj, const char *name, const bool *v)
{
    Error *local_err = NULL;
    object_property_add(obj, name, "bool", cm_property_get_bool,
            cm_property_set_bool,
            NULL, (void *) v, &local_err);
    if (local_err) {
        error_report("Adding property %s for %s failed: %s.", name,
                object_get_typename(obj), error_get_pretty(local_err));
        exit(1);
    }
}
static void cm_property_get_uint64_ptr(Object *obj, Visitor *v, void *opaque,
        const char *name, Error **errp)
{
    uint64_t value = *(uint64_t *) opaque;
    visit_type_uint64(v, &value, name, errp);
}

static void cm_property_set_uint64_ptr(Object *obj, struct Visitor *v,
        void *opaque, const char *name, Error **errp)
{
    Error *local_err = NULL;
    uint64_t value;
    visit_type_uint64(v, &value, name, &local_err);
    if (!local_err) {
        *((uint64_t *) opaque) = value;
    }
    error_propagate(errp, local_err);
}

void cm_object_property_add_uint64(Object *obj, const char *name,
        const uint64_t *v)
{
    Error *local_err = NULL;
    object_property_add(obj, name, "uint64", cm_property_get_uint64_ptr,
            cm_property_set_uint64_ptr, NULL, (void *) v, &local_err);
    if (local_err) {
        error_report("Adding property %s for %s failed: %s.", name,
                object_get_typename(obj), error_get_pretty(local_err));
        exit(1);
    }
}

static void cm_property_get_uint32_ptr(Object *obj, Visitor *v, void *opaque,
        const char *name, Error **errp)
{
    uint32_t value = *(uint32_t *) opaque;
    visit_type_uint32(v, &value, name, errp);
}

static void cm_property_set_uint32_ptr(Object *obj, struct Visitor *v,
        void *opaque, const char *name, Error **errp)
{
    Error *local_err = NULL;
    uint32_t value;
    visit_type_uint32(v, &value, name, &local_err);
    if (!local_err) {
        *((uint32_t *) opaque) = value;
    }
    error_propagate(errp, local_err);
}

void cm_object_property_add_uint32(Object *obj, const char *name,
        const uint32_t *v)
{
    Error *local_err = NULL;
    object_property_add(obj, name, "uint32", cm_property_get_uint32_ptr,
            cm_property_set_uint32_ptr, NULL, (void *) v, &local_err);
    if (local_err) {
        error_report("Adding property %s for %s failed: %s.", name,
                object_get_typename(obj), error_get_pretty(local_err));
        exit(1);
    }
}

static void cm_property_get_uint16_ptr(Object *obj, Visitor *v, void *opaque,
        const char *name, Error **errp)
{
    uint16_t value = *(uint16_t *) opaque;
    visit_type_uint16(v, &value, name, errp);
}

static void cm_property_set_uint16_ptr(Object *obj, struct Visitor *v,
        void *opaque, const char *name, Error **errp)
{
    Error *local_err = NULL;
    uint16_t value;
    visit_type_uint16(v, &value, name, &local_err);
    if (!local_err) {
        *((uint16_t *) opaque) = value;
    }
    error_propagate(errp, local_err);
}

void cm_object_property_add_uint16(Object *obj, const char *name,
        const uint16_t *v)
{
    Error *local_err = NULL;
    object_property_add(obj, name, "uint16", cm_property_get_uint16_ptr,
            cm_property_set_uint16_ptr, NULL, (void *) v, &local_err);
    if (local_err) {
        error_report("Adding property %s for %s failed: %s.", name,
                object_get_typename(obj), error_get_pretty(local_err));
        exit(1);
    }
}

static void cm_property_get_uint8_ptr(Object *obj, Visitor *v, void *opaque,
        const char *name, Error **errp)
{
    uint8_t value = *(uint8_t *) opaque;
    visit_type_uint8(v, &value, name, errp);
}

static void cm_property_set_uint8_ptr(Object *obj, struct Visitor *v,
        void *opaque, const char *name, Error **errp)
{
    Error *local_err = NULL;
    uint8_t value;
    visit_type_uint8(v, &value, name, &local_err);
    if (!local_err) {
        *((uint8_t *) opaque) = value;
    }
    error_propagate(errp, local_err);
}

void cm_object_property_add_uint8(Object *obj, const char *name,
        const uint8_t *v)
{
    Error *local_err = NULL;
    object_property_add(obj, name, "uint8", cm_property_get_uint8_ptr,
            cm_property_set_uint8_ptr, NULL, (void *) v, &local_err);
    if (local_err) {
        error_report("Adding property %s for %s failed: %s.", name,
                object_get_typename(obj), error_get_pretty(local_err));
        exit(1);
    }
}

static void cm_property_get_int16_ptr(Object *obj, Visitor *v, void *opaque,
        const char *name, Error **errp)
{
    int16_t value = *(int16_t *) opaque;
    visit_type_int16(v, &value, name, errp);
}

static void cm_property_set_int16_ptr(Object *obj, struct Visitor *v,
        void *opaque, const char *name, Error **errp)
{
    Error *local_err = NULL;
    int16_t value;
    visit_type_int16(v, &value, name, &local_err);
    if (!local_err) {
        *((int16_t *) opaque) = value;
    }
    error_propagate(errp, local_err);
}

void cm_object_property_add_int16(Object *obj, const char *name,
        const int16_t *v)
{
    Error *local_err = NULL;
    object_property_add(obj, name, "int16", cm_property_get_int16_ptr,
            cm_property_set_int16_ptr, NULL, (void *) v, &local_err);
    if (local_err) {
        error_report("Adding property %s for %s failed: %s.", name,
                object_get_typename(obj), error_get_pretty(local_err));
        exit(1);
    }
}

/* ------------------------------------------------------------------------- */

