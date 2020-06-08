#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/syscalls.h>
#include <asm/unistd.h>
#include <linux/sched.h>
#include <linux/dirent.h>
#include <linux/slab.h>
#include <linux/version.h>

static unsigned long * get_syscall_table(void)
{
    return NULL;
}

static int __init init_rootkit(void)
{
    printk(KERN_INFO "%p\n", get_syscall_table());

    return 0;
}

static void __exit cleanup_rootkit(void)
{
    
}  

module_init(init_rootkit);
module_exit(cleanup_rootkit);
