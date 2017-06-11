#include <linux/module.h> /* Needed by all modules */
#include <linux/kernel.h> /* Needed for KERN_INFO */
#include <linux/init.h> /* Needed for the macros */
#include <linux/sched.h>
#include <linux/printk.h>

// char *pslist();

static char * pslist(void)
{
    // Code to get the parent process euid
    return "hello__called";
}

EXPORT_SYMBOL(pslist);

static int __init hello_2_init(void)
{
	printk(KERN_INFO "Hello, world 2\n");

	struct task_struct *task;

	printk("----------process list from ---------- \n");
    for_each_process(task)
        pr_info(" Parent process is %s and process ID is [%d]\n", task->comm, task->pid);

	return 0;
}

static void __exit hello_2_exit(void)
{
	printk(KERN_INFO "Goodbye, world 2\n");
}

module_init(hello_2_init);
module_exit(hello_2_exit);
