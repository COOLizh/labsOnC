#include "stdafx.h"
#include <windows.h>

int GetInteger()
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

		printf_s("Необходимо ввести число.\nПовторите ввод : ");
	}
}


int main()
{
	int k = 0, result = 0;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Вводите номер от 1 до 900: ");

	while (k < 1 || k > 900)
	{
		k = GetInteger();
	}

	result = k + 99;

	printf("Это число : %d\n", result);

	return 0;
}
