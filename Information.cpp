#include <stdio.h>
#include "Information.h"
struct ROUTE
{
	int num;
	char type;
	char start;
	char finish;
	int time;
	struct ROUTE* next;
};
void Info(struct ROUTE* X, char a, char b)
{
	int bus = 0, tram = 0, taxi = 0;
	struct ROUTE* sw, * best;
	sw = X;
	best = NULL;
	for (; sw != NULL; sw = sw->next)
		if (sw->start == a && sw->finish == b)
			switch (sw->type)
			{
			case 'A': bus++; break;
			case 'T': tram++; break;
			case 'M': taxi++; break;
			default: break;
			}
	printf("\nПо указанным пунктам найдены:\nМаршрутов автобусов:%d\tМаршрутов трамваев:%d\tМаршрутов такси:%d", bus, tram, taxi);
}