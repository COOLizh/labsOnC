#include "stdafx.h"
#include <windows.h>
#define N 128

int main()
{
	FILE *fp;
	char str[N];
	int counter = 0, max = 0;

	system("color 0A");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if ((fp = fopen("C:\\Users\\Pavilion\\Desktop\\Лабы 2 сем\\Программирование\\lab4\\lab4_2\\text.txt", "r+")) == NULL) 
	{
		printf("Cannot open file.\n");
		exit(1);
	}

	printf("Text in file is : \n---------------------------------------------------------------\n");
	while (fgets(str, N, fp) != NULL)
	{
		printf(str);

		for (int i = 0; i <= strlen(str); i++)
		{
			if (str[i] != ' ' && str[i] != '!' && str[i] != '?' && str[i] != '.' && str[i] != ',' && str[i] != '\n' && str[i] != '\0')
				counter++;

			else
				counter = 0;

			if (counter > max)
				max = counter;
		}
	}
	fclose(fp);

	int *mass = (int*)malloc(sizeof(int)*max);
	for (int i = 0; i < max; i++)
		mass[i] = 0;

	counter = 0;
	fopen("C:\\Users\\Pavilion\\Desktop\\Лабы 2 сем\\Программирование\\lab4\\lab4_2\\text.txt", "r+");
	while (fgets(str, N, fp) != NULL)
	{
		for (int i = 0; i <= strlen(str); i++)
		{
			if (str[i] != ' ' && str[i] != '!' && str[i] != '?' && str[i] != '.' && str[i] != ',' && str[i] != '\n' && str[i] != '\0')
				counter++;

			else 
			{
				mass[counter - 1]++;
				counter = 0;
			}
		}
	}

	printf("\n---------------------------------------------------------------\nHistogram of word lengths : \n");
	for (int j = 0; j < max; j++)
	{
		printf("%d|\t\t", j + 1);
		{
			for (int i = 0; i < mass[j]; i++)
				printf("*");
		}
		printf("\n");
	}

	fclose(fp);
	free(mass);
    return 0;
}
