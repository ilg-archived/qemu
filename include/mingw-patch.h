#ifndef QEMU_MINGW_PATCH_H
#define QEMU_MINGW_PATCH_H

#ifdef __MINGW32__
    #if !defined(ffs)
    #define ffs __builtin_ffs
    #endif
#endif

#endif
