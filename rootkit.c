#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init init_rootkit(void)
{

}

static void __exit cleanup_rootkit(void)
{
    
}  

module_init(init_rootkit);
module_exit(cleanup_rootkit);
