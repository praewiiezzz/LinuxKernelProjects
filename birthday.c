nclude <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/list.h>
#include <linux/slab.h>

typedef struct birthday {
        int day ;
        int month ;
        int year ;
        struct list_head list ;
}birthday;

static LIST_HEAD(birthday_list);


/* This function is called when the module is loaded/ */
int simple_init(void)
{
	printk(KERN_INFO "Loading Module\n");
	birthday *person ;
	int i = 0 ;
	for(i = 0 ; i < 5 ; i++){
		person = kmalloc(sizeof(*person),GFP_KERNEL);
		person->day = 1+i ;
		person->month = 8+i ;
		person->year = 1995+i ;
		INIT_LIST_HEAD(&person->list);
		list_add_tail(&person->list,&birthday_list);
	}
	birthday *ptr ,*next;
	list_for_each_entry(ptr,&birthday_list,list){
		printk(KERN_INFO "Birthday is %d %d %d\n",ptr->day,ptr->month,ptr->year);
	}
	return 0;
}

/*this function is called when the module is removed. */
void simple_exit(void)
{
	printk(KERN_INFO "Removing Module\n");
	birthday *ptr, *next;
    	list_for_each_entry_safe(ptr, next, &birthday_list, list){
        	printk(KERN_INFO "Removing birthdaythat  %d %d %d\n",ptr->day,ptr->month,ptr->year);
	        list_del(&ptr->list);
        	kfree(ptr);
    	}
	printk(KERN_INFO "Check removing");
	list_for_each_entry(ptr,&birthday_list,list){
                printk(KERN_INFO "Birthday is %d %d %d\n",ptr->day,ptr->month,ptr->year);
    }
}

/* Maceos for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
