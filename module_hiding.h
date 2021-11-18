#ifndef MODULE_HIDING_H
#define MODULE_HIDING_H

#include <linux/module.h>

void hide_module(struct module *mod);
void unhide_module(struct module *mod);

#endif
