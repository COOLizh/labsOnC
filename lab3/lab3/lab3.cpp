#include "stdafx.h"
#include <malloc.h>
#include <stdbool.h>
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
		else 
			return number;

		printf_s("You must enter a number.\nRepeat input: ");
	}
}

double getDouble()
{
	double number;
	char c;
	while (1)
	{
		if (!scanf_s("%lf", &number) || getchar() != '\n')
		{
			while ((c = getchar()) != '\n' && c != EOF);
		}
		else 
			return number;

		printf_s("You must enter a number.\nRepeat input: ");
	}
}

int main()
{
	int r = 0, c = 0, j = -1, i = -1;
	char choice = ' ';

	while (r <= 0 || INT_MAX < r)
	{
		printf("Enter the number of rows of the matrix : ");
		r = getInteger();
	}

	while (c <= 0 || INT_MAX < c)
	{
		printf("Enter the number of cols of the matrix : ");
		c = getInteger();
	}

	double **mass = (double**)malloc(sizeof(double*)*r);
	for (int i = 0; i < r; i++)
		mass[i] = (double*)malloc(sizeof(double)*c);

	bool **check = (bool**)malloc(sizeof(bool*)*r);
	for (int i = 0; i < r; i++)
		check[i] = (bool*)malloc(sizeof(bool)*c);

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			check[i][j] = false;

	printf("\nEnter i, j, mass[i][j] :\n");
	while (1)
	{
		if (mass[0][0] == 0 && j == 0 && i == 0)
			break;
		else
		{
			while (1)
			{
				printf("i = ");
				i = getInteger();
				if (i >= 0 && INT_MAX > i && i < r)
					break;
			}

			while (1)
			{
				printf("j = ");
				j = getInteger();
				if (j >= 0 && INT_MAX > j && j < c)
					break;
			}

			if (check[i][j] == false)
			{
				check[i][j] = true;
				while (1)
				{
					printf("mass[%d][%d] = ", i, j);
					mass[i][j] = getDouble();
					if (INT_MAX > mass[i][j] && INT_MIN < mass[i][j])
						break;
				}
				printf("\n");
				continue;
			}
			else
			{
				while (1)
				{
					printf("\nDo you want to change cell values in an array ?\n1 - yes\n0 - no\n");
					choice = getch();

					switch (choice)
					{
						case '0':
							printf("The value is not changed. Continue typing.\n\n");
							break;

						case '1':
							printf("Enter value of mass[%d][%d] : ", i, j);
							while (1)
							{
								mass[i][j] = getDouble();
								if (INT_MAX > mass[i][j] && INT_MIN < mass[i][j])
									break;
							}
							printf("The value is changed. Continue typing.\n\n");
							break;

						default:
							printf("Wrong symbol.\nTry again...\n\n");
							break;
					}

					if (choice == '0' || choice == '1')
						break;
				}
			}
		}
	}
	
	printf("Your matrix : \n");
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (check[i][j] == false)
				printf("*\t\t");
			else
				printf("%lf\t", mass[i][j]);
		}
		printf("\n");
	}

	free(mass);
	free(check);
	return 0;
}
