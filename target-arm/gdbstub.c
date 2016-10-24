/*
 * ARM gdb server stub
 *
 * Copyright (c) 2003-2005 Fabrice Bellard
 * Copyright (c) 2013 SUSE LINUX Products GmbH
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */
#include "qemu/osdep.h"
#include "qemu-common.h"
#include "cpu.h"
#include "exec/gdbstub.h"

#if defined(CONFIG_GNU_ARM_ECLIPSE)
uint32_t helper_v7m_mrs(CPUARMState *env, uint32_t reg);
void helper_v7m_msr(CPUARMState *env, uint32_t reg, uint32_t val);
#endif /* defined(CONFIG_GNU_ARM_ECLIPSE) */

/* Old gdb always expect FPA registers.  Newer (xml-aware) gdb only expect
   whatever the target description contains.  Due to a historical mishap
   the FPA registers appear in between core integer regs and the CPSR.
   We hack round this by giving the FPA regs zero size when talking to a
   newer gdb.  */

int arm_cpu_gdb_read_register(CPUState *cs, uint8_t *mem_buf, int n)
{
    ARMCPU *cpu = ARM_CPU(cs);
    CPUARMState *env = &cpu->env;

    if (n < 16) {
        /* Core integer register.  */
        return gdb_get_reg32(mem_buf, env->regs[n]);
    }
    if (n < 24) {
        /* FPA registers.  */
        if (gdb_has_xml) {
            return 0;
        }
        memset(mem_buf, 0, 12);
        return 12;
    }
    switch (n) {
    case 24:
        /* FPA status register.  */
        if (gdb_has_xml) {
            return 0;
        }
        return gdb_get_reg32(mem_buf, 0);
    case 25:
        /* CPSR */
        return gdb_get_reg32(mem_buf, cpsr_read(env));

#if defined(CONFIG_GNU_ARM_ECLIPSE)
    case 26:
        /* MSP */
        return gdb_get_reg32(mem_buf, helper_v7m_mrs(env, 8));
    case 27:
        /* PSP */
        return gdb_get_reg32(mem_buf, helper_v7m_mrs(env, 9));
    case 28:
        /* PRIMASK */
        return gdb_get_reg32(mem_buf, helper_v7m_mrs(env, 16));
    case 29:
        /* BASEPRI */
        return gdb_get_reg32(mem_buf, helper_v7m_mrs(env, 17));
    case 30:
        /* FAULTMASK */
        return gdb_get_reg32(mem_buf, helper_v7m_mrs(env, 19));
    case 31:
        /* CONTROL */
        return gdb_get_reg32(mem_buf, helper_v7m_mrs(env, 20));
#endif /* defined(CONFIG_GNU_ARM_ECLIPSE) */

    }
    /* Unknown register.  */
    return 0;
}

int arm_cpu_gdb_write_register(CPUState *cs, uint8_t *mem_buf, int n)
{
    ARMCPU *cpu = ARM_CPU(cs);
    CPUARMState *env = &cpu->env;
    uint32_t tmp;

    tmp = ldl_p(mem_buf);

    /* Mask out low bit of PC to workaround gdb bugs.  This will probably
       cause problems if we ever implement the Jazelle DBX extensions.  */
    if (n == 15) {
        tmp &= ~1;
    }

    if (n < 16) {
        /* Core integer register.  */
        env->regs[n] = tmp;
        return 4;
    }
    if (n < 24) { /* 16-23 */
        /* FPA registers (ignored).  */
        if (gdb_has_xml) {
            return 0;
        }
        return 12;
    }
    switch (n) {
    case 24:
        /* FPA status register (ignored).  */
        if (gdb_has_xml) {
            return 0;
        }
        return 4;
    case 25:
        /* CPSR */
        cpsr_write(env, tmp, 0xffffffff, CPSRWriteByGDBStub);
        return 4;

#if defined(CONFIG_GNU_ARM_ECLIPSE)
    case 26:
        /* MSP */
        helper_v7m_msr(env, 8, tmp);
        return 4;
    case 27:
        /* PSP */
        helper_v7m_msr(env, 9, tmp);
        return 4;
    case 28:
        /* PRIMASK */
        helper_v7m_msr(env, 16, tmp);
        return 4;
    case 29:
        /* BASEPRI */
        helper_v7m_msr(env, 17, tmp);
        return 4;
    case 30:
        /* FAULTMASK */
        helper_v7m_msr(env, 19, tmp);
        return 4;
    case 31:
        /* CONTROL */
        helper_v7m_msr(env, 20, tmp);
        return 4;
#endif /* defined(CONFIG_GNU_ARM_ECLIPSE) */

        }
    /* Unknown register.  */
    return 0;
}
