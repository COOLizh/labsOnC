#include "stdafx.h"
#include <limits.h>

int getInteger()
{
	int number;
	char c;

	while (1)
	{
		if (!scanf_s("%d", &number) || getchar() != '\n')
		{
			while ((c = getchar()) != '\n' && c != EOF);
		}
		else return number;

		printf_s("Wrong degree.\nEnter integer : ");
	}
}

typedef struct degree
{
	int val;
	struct degree *next;
	struct degree *prev;
};

//инициализация списка
struct degree* init(int a)
{
	struct degree *dgr = (struct degree*)malloc(sizeof(struct degree));
	dgr->val = a;
	dgr->next = NULL;
	dgr->prev = NULL;

	return dgr;
}

//добавление элемента
struct degree* addelem(struct degree *lst, int number)
{
	struct degree *temp, *p;

	temp = (struct dergree*)malloc(sizeof(struct degree));

	temp->val = number;

	temp->next = lst;
	lst->prev = temp;

	temp->prev = NULL;

	return(temp);
}

// Просмотр списка
void show(struct degree *lst)
{
	struct degree *p;
	p = lst;

	while (lst->prev != NULL)
		lst = lst->prev;

	do {
		printf("%d", lst->val);
		lst = lst->next;
	} while (lst);
}

int main()
{
	int n = 0, counter = 1, b = 0, tmp = 0;
	struct degree *current = NULL, *head = NULL;


	printf("Enter the power of the number three (>=100) : ");
	while(n < 99 && n < INT_MAX)
		n = getInteger();

	current = init(3);
	head = current;

	for (int i = 1; i <= n; i++)
	{
		if (current)
		{
			while (current->prev)
				current = current->prev;
		}

		if (i == n)
		{
			printf("3^%d = ", i);
			show(current);
			printf("\n");
		}

		b = 0;

		while (current->prev)
			current = current->prev;
		int counter = 0;
		do
		{
			if (counter) current = current->next;
			current->val *= 3;
			counter++;


		} while (current->next);
		counter = 0;

		do {
			if (counter)
				current = current->prev;

			current->val += b;
			tmp = current->val;
			current->val = current->val % 10;
			b = tmp / 10;


			counter++;

		} while (current->prev);



		if (b > 0) 
			current = addelem(current, b);
	}

	return 0;
}
