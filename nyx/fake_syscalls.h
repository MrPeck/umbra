#ifndef FAKE_SYSCALLS_H
#define FAKE_SYSCALLS_H

#include <linux/syscalls.h>

#define TAINTED_PREFIX "Aa1234"

asmlinkage long sys_getdents64_fake(const struct pt_regs *regs);

#endif
