#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/sched.h>

int simple_init(void)
{
	struct task_struct *task;
	for_each_process(task)
	{
 		printk(KERN_INFO "task name: %15s state :%d process id :%d ",task->comm,task->state,task->pid);
	}
	
}

void simple_exit(void)
{
	printk(KERN_INFO "Removing Module\n"); 
}



module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Linux Kernel Module for Listing Tasks : Assignment1");
MODULE_AUTHOR("Chutikan Noikanchana");


