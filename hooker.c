#include "hooker.h"

static inline void write_cr0_forced(unsigned long val)
{
    asm volatile("mov %0,%%cr0": "+r" (val), "+m" (__force_order));
}

static inline void unprotect_memory(void)
{
    write_cr0_forced(read_cr0() & ~X86_CR0_WP);
}

static inline void protect_memory(void)
{
    write_cr0_forced(read_cr0() | X86_CR0_WP);
}

static void hook_syscall(unsigned long nr, sys_call_ptr_t faddr)
{
    unprotect_memory();

    sys_call_table_copy[nr] = sys_call_table_original[nr];
    sys_call_table_original[nr] = faddr;

    protect_memory();
}

static void unhook_all(void)
{
    int i;

    unprotect_memory();

    for (i = 0; i < NR_syscalls; i++)
        if (sys_call_table_copy[i]) 
            sys_call_table_original[i] = sys_call_table_copy[i];

    protect_memory();
}
