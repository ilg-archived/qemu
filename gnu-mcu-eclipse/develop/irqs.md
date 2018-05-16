# Interrupts

QEMU uses a custom notification mechanism not only to emulate interrupts, but also to pass values from one object to another.

This mechanism uses `TYPE_IRQ` objects to store the pointer of the interrupt handler. Arrays of such objects are allocated in the incoming end (like NVIC, for actual interrupts, but also other objects that are driven by values set in other parts, like LEDs, etc). 

The outgoing end of this mechanism uses plain pointers to `TYPE_IRQ` objects. 

This simple implementation has limitations, as oposed to usual observer pattern implementations, it is not possible to register any number of listeners to a single notifier; the application must keep separate pointers to different `TYPE_IRQ` objects and explicitly notify them all.

## Interrupts as named properties of devices

Althoug interrupts can be created and initialised separately, the recommended way is to create them as named properties associated to `TYPE_DEVICE` objects. The device DeviceState structure includes a list (sugestively named `gpios`) which includes elements of type NamedGPIOList, that basically have a name and a pointer to an array of `TYPE_IRQ` objects.


## Incoming

Incoming interrupts are objects that process raise/lower actions invoked by other objects.

To create an array of incoming interrupts in a device use `cm_irq_init_in()` in the instance init callback:

```
cm_irq_init_in(DEVICE(obj), xxx_irq_handler, "xxx-in", size);

```

The names are arbitrary, but it is recommended to suffix incoming interrupts with `-in`.

The handler function should have the following prototype:

```
static void gpio_led_irq_handler(void *opaque, int index, int level)
{
    // GPIOLEDState *state = GPIO_LED_STATE(opaque);
    // ...
}
```


## Outgoing

Outgoing interrupts are not separate objects, but links to incoming interrupts. Multiple outgoing interrupts can point to the same incoming interrupt.

Arrays of pointers to `TYPE_DEVICE` objects must be defined in the object state.

```
typedef struct {
  qemu_irq out_irq[N];
} XxxState;
```

To be able to conveniently address these arrays at global level, use `cm_irq_init_out()` in the instance init callback:

```
cm_irq_init_out(DEVICE(obj), &state->irq_out, "xxx-out", N);

```

## Connect

Each output interrupt must be individually and explicitly connected to its corresponding incoming interrupt.

For example to connect the button to one GPIO pin, use something like this in the realize callback:

```
cm_irq_connect(DEVICE(button), IRQ_BUTTON_GPIO_OUT, 0,
               DEVICE(gpio), IRQ_GPIO_IDR_IN, gpio_bit);
```

## Use

Interrupts can be raised or lowered:

```
cm_irq_set(state->out_irq[i], condition ? 1 : 0);

cm_irq_raise(state->out_irq[i]);
cm_irq_lower(state->out_irq[i]);
```

Generally each outgoing interrupt should be connected to one and only one incoming interrupt, with multiple outgoing interrupts being allowed to connect to the same incoming interrupt.

For NVIC exception, each outgoing interrupt should be connected to one NVIC exception, and multiple outgoing interrupt can be connected to the same NVIC exception:

```
cm_irq_connect(dev, IRQ_EXTI_OUT, 5, nvic, IRQ_NVIC_IN, STM32F10X_MD_EXTI9_5_IRQn);
cm_irq_connect(dev, IRQ_EXTI_OUT, 6, nvic, IRQ_NVIC_IN, STM32F10X_MD_EXTI9_5_IRQn);
// ...
```

## Reset

The entire outgoing array can be reset during the reset callback:

```
static void xxx_reset_callback(DeviceState *dev)
{
  int i;
  XxxxState *state = XXX_STATE(dev);
  
  for (i = 0; i < N; i++) {
    cm_irq_lower(state->out_irq[i]);
  }
}
```

For regular devices this might be redundant, but for some devices, like active low buttons, the inactive value is 1, and must be explicitly set.

```
cm_irq_raise(button->out_irq);

```

Note: for this to be effective, the button must be reset **after** the GPIO port.


## Core interrupt processing

In `cpu-exec.c`, `cpu_exec()` prepares a `sigsetjmp()` context for exception handling. The context is restored by `cpu_loop_exit()`, called generally from from `raise_exception()`.

Then checks `cpu_handle_exception()` and possibly `cpu_handle_interrupt()`.

`cpu_handle_exception()` uses `cpu->exception_index` and possibly calls `cc->do_interrupt(cpu)`.

`cpu_handle_interrupt()` calls `cc->cpu_exec_interrupt(cpu, interrupt_request)`, which is pointing to `arm_v7m_cpu_exec_interrupt()`.


## Pending an exception

`cortexm_nvic_set_pending_exception()` 

`gic_set_pending_private()` checks if pending, and, if not sets it (`s->irq_state[irq].pending |= (cm)`), then calls `gic_update()`.

`gic_update()` enumerates all `s->num_irq`, identifies the highest pending and calls `qemu_set_irq(s->parent_irq[cpu], irq_level)` which calls `arm_cpu_set_irq()`.

## Pending an interrupt

`cortexm_nvic_set_pending_interrupt()` 

