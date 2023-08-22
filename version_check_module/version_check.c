#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <generated/utsrelease.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ankit Kokane");
MODULE_DESCRIPTION("Kernel version check module");

static char *input_version;

module_param(input_version, charp, 0644);
MODULE_PARM_DESC(input_version, "Input kernel version to check");

static int __init version_check_init(void) {
    pr_info("Version check module loaded.\n");
    pr_info("User provided kernel version: %s\n", input_version);

    if (strcmp(input_version, UTS_RELEASE) == 0) {
        pr_info("Your input matches current kernel version.\n");
    } else {
        pr_info("Your input does not match current kernel version.\n");
        pr_info("Correct kernel version is: %s\n", UTS_RELEASE);
    }

    return 0;
}

static void __exit version_check_exit(void) {
    pr_info("Version check module unloaded.\n");
}

module_init(version_check_init);
module_exit(version_check_exit);
