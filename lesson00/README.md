Here's the line-by-line explanation of the code.

Though this is a beginner-friendly tutorial, as every aspiring kernel developer, one is required to have knowledge of C-programming language and basic command-line tools.

First we include the necessary header files
```c
		#include <linux/init.h>			// Defines __init and __exit macros
		#include <linux/module.h>		// Required to load and unload modules
```
Do not confuse these header files with the ones inside `/usr/include/` and `/usr/include/linux/` directories. These are user-space header files and are never used in kernel-space. Linux kernel source has its own header files located in `/lib/modules/$(uname -r)/build/include/` and `/lib/modules/$(uname -r)/build/include/linux/` directories.

```c
		#define DEVICE_NAME "basic"		// The name of our module


		// We define our function bodies first to be used by module_init() and module_exit() later in the code.
		
		static int __init basic_init(void)
		{
			pr_debug(DEVICE_NAME ": Module initialized!\n");
			return 0;
		}

		static void __exit basic_exit(void)
		{
			pr_debug(DEVICE_NAME ": Exited!\n");
		}
```
We use pr_debug for easy removal of kernel messages like the ones in the code above. More of this when we get to the Makefile topic.

And now the following are the real functions that gets executed when modules are being loaded/unloaded, it uses the functions we defined earlier as their argument.

```c
		module_init(basic_init);
		module_exit(basic_exit);
```
The following are optional, these are shown when executing `sudo modinfo <kernel module>`.
```c
		MODULE_LICENSE("GPL v2");
		MODULE_AUTHOR("Aldrin Tadas");
		MODULE_DESCRIPTION("A basic kernel module");
		MODULE_VERSION("0.1");
```
