#include <stdio.h>
#include "Longest.h"
struct ROUTE
{
	int num;
	char type;
	char start;
	char finish;
	int time;
	struct ROUTE* next;
};
int GetLongestNum(struct ROUTE* X, char a, char b)
{
	struct ROUTE *sw, *best;
	sw = X;
	best = NULL;
	for (; sw != NULL; sw = sw->next)
		if (sw->start == a && sw->finish == b)
			if (best == NULL)
				best = sw;
			else if ((sw->time) > (best->time))
				best = sw;
	return best->num;
}