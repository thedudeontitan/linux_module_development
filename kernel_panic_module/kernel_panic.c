#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/printk.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Null Pointer Dereference Module");
MODULE_AUTHOR("Ankit Kokane");

static int __init null_deref_init(void) {
    int *ptr = NULL;
    
    pr_info("Loading kernel panic module\n");
    pr_info("Creating a kernel panic with NULL pointer dereferencing\n");
    *ptr = 10;
    
    return 0;
}

static void __exit null_deref_exit(void) {
    pr_info("kernel panic module unloaded\n");
}

module_init(null_deref_init);
module_exit(null_deref_exit);

