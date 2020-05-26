#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "List.h"
struct ROUTE
{
	int num;
	char type;
	char start;
	char finish;
	int time;
	struct ROUTE* next;
};

void LoadRoutes(struct ROUTE** X, char* FN)
{
	FILE* RL;
	*X = NULL;
	char RouteInfo[42];
	if (fopen_s(&RL, FN, "r") != 0)
		printf("\nNo File!");
	else
	{
		while (fgets(RouteInfo, 42, RL) != NULL)
		{
			struct ROUTE* pt;
			pt = (struct ROUTE*) malloc(sizeof(struct ROUTE));
			pt->num = (RouteInfo[6] - 48) * 10 + (RouteInfo[7] - 48);
			pt->type = RouteInfo[14];
			pt->start = RouteInfo[22];
			pt->finish = RouteInfo[31];
			pt->time = (RouteInfo[38] - 48) * 10 + (RouteInfo[39] - 48);
			pt->next = *X;
			*X = pt;
		}
	}
	fclose(RL);
}