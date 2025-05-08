/*
* stop.c - Illustration of multi filed modules
*/

#include <linux/kernel.h>
#include <linux/module.h>

void cleanup_module(void) {
    pr_info("Short is the life of kernel module\n");
}

MODULE_LICENSE("GPL");
