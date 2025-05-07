/*
*  hello-4.c - Demonstrates module documentation
*/

#include <linux/init.h> /* for the macros */
#include <linux/module.h> /* for all modules */
#include <linux/printk.h> /* for pr_info() */

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A sample driver");

static int __init init_hello_4(void) {
    pr_info("Hello, world 4\n");
    return 0;
}

static void __exit cleanup_hello_4(void) {
    pr_info("Goodbye, world 4\n");
}

module_init(init_hello_4);
module_exit(cleanup_hello_4);
