#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include "List.h"
#include "StartFinish.h"
#include "Longest.h"
#include "Information.h"
using namespace std;
struct ROUTE
{
	int num;
	char type;
	char start;
	char finish;
	int time;
	struct ROUTE* next;
};
void PrintAll(struct ROUTE* X)
{
	struct ROUTE* p;
	for (p = X; p->next != NULL; p = p->next)
		printf("\nНомер:%d Тип:%c Начальный пункт:%c Конечный пункт:%c Время в пути:%d", p->num, p->type, p->start, p->finish, p->time);
}
int main()
{
	//to use russian language
	setlocale(LC_ALL, "ru");
	struct ROUTE* X;
	char FN[] = "ROUTES.txt";
	char a, b;

	//Creating list with struct r frow file FN
	LoadRoutes(&X, FN);
	PrintAll(X);

	//Show All Routes from A to B
	printf("\nВведите начальный пункт:");
	cin >> a;
	printf("\nВвелите конечный пункт:");
	cin >> b;
	printf("\nПо указанным пунктам найдены маршруты:");
	ShowStartFinish(X, a, b);

	//Get Longest Number
	printf("\nВведите начальный пункт:");
	cin >> a;
	printf("\nВвелите конечный пункт:");
	cin >> b;
	int LN = GetLongestNum(X, a, b);
	printf("\nСамый долгий маршрут по указанным точкам №%d", LN);

	//Show count routes from A to B
	printf("\nВведите начальный пункт:");
	cin >> a;
	printf("\nВвелите конечный пункт:");
	cin >> b;
	Info(X, a, b);
}

