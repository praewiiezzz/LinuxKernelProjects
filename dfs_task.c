#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/sched.h>

void dfs_tasks(struct task_struct *task)
{
	struct task_struct *nextTask;
	struct list_head *list;

	list_for_each(list, &task->children)
	{
		nextTask = list_entry(list,struct task_struct,sibling);
		printk(KERN_INFO "task name: %15s state :%d process id :%d ",task->comm,task->state,task->pid);
		dfs_tasks(nextTask);
	}

}

int simple_init(void)
{
	printk(KERN_INFO "Loading Module\n"); 
	dfs_tasks(&init_task);
	return 0;
	
}

void simple_exit(void)
{
	printk(KERN_INFO "Removing Module\n"); 
}



module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Iterating over Tasks with Depth-First Search Tree");
MODULE_AUTHOR("Chutikan Noikanchana");


