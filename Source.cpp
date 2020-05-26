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
		printf("\n�����:%d ���:%c ��������� �����:%c �������� �����:%c ����� � ����:%d", p->num, p->type, p->start, p->finish, p->time);
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
	printf("\n������� ��������� �����:");
	cin >> a;
	printf("\n������� �������� �����:");
	cin >> b;
	printf("\n�� ��������� ������� ������� ��������:");
	ShowStartFinish(X, a, b);

	//Get Longest Number
	printf("\n������� ��������� �����:");
	cin >> a;
	printf("\n������� �������� �����:");
	cin >> b;
	int LN = GetLongestNum(X, a, b);
	printf("\n����� ������ ������� �� ��������� ������ �%d", LN);

	//Show count routes from A to B
	printf("\n������� ��������� �����:");
	cin >> a;
	printf("\n������� �������� �����:");
	cin >> b;
	Info(X, a, b);
}

