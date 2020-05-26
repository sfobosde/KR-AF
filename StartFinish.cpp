#include <stdio.h>
#include "StartFinish.h"
struct ROUTE
{
	int num;
	char type;
	char start;
	char finish;
	int time;
	struct ROUTE* next;
};
void ShowStartFinish(struct ROUTE* X, char a, char b)
{
	struct ROUTE* p;
	for (p = X; p->next != NULL; p = p->next)
		if(p->start == a && p->finish == b)
			printf("\nRoute:%d Type:%c Time:%d", p->num, p->type, p->time);
}