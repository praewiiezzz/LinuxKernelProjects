#include<linux/list.h>
#include<linux/types.h>

struct birthday {
	int day;
	int month;
	int year;
	struct list_head list;
}

statuc LIST_HEAD(birthday_list);

struct birthday *person;

person = kmalloc(sizeof(*person), GFP_KERNEL);
person->day = 2;
person->month = 8;
person->year = 1995;
INIT_LIST_HEAD(&person->list);

list_add_tail(&person->list, &birthday_list);

