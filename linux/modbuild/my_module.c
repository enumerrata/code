#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

void test(void);

static int __init init_my_module(void) {
  printk(KERN_INFO "Hello, my module!\n");
  test();
  return 0;
}

static void __exit exit_my_module(void) {
  printk(KERN_INFO "Bye, my module!\n");
}

module_init(init_my_module);
module_exit(exit_my_module);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("csprojectedu");
