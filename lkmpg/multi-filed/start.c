/*
* start.c - Illustration of multi filed modules
*/

#include <linux/kernel.h>
#include <linux/module.h>

int init_module(void) {
    pr_info("Hello, world - this is a kernel speaking\n");
    return 0;
}

MODULE_LICENSE("GPL");
