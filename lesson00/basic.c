#include <linux/init.h>
#include <linux/module.h>

#define DEVICE_NAME "basic"

/* Function names here are arbitrary
 * suffixed with _init and _exit
 * for clarity.
 */

int __init basic_init(void)
{
	pr_debug(DEVICE_NAME ": Module initialized!\n");
	return 0;
}

void __exit basic_exit(void)
{
	pr_debug(DEVICE_NAME ": Exited!\n");
}

module_init(basic_init);
module_exit(basic_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Aldrin Tadas");
MODULE_DESCRIPTION("A basic kernel module");
MODULE_VERSION("0.1");
