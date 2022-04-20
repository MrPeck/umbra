#ifndef HOOKER_H
#define HOOKER_H

#include <asm/syscall.h>
#include <asm/unistd.h>

void set_sys_call_table_addr(sys_call_ptr_t *sys_call_table);
void hook_syscall(unsigned long nr, sys_call_ptr_t faddr);
void unhook_all(void);
long call_original_syscall(unsigned long nr, const struct pt_regs *regs);

#endif
