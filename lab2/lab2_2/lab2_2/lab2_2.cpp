#include "stdafx.h"
#include <math.h>
#include <windows.h>
#include <limits.h>

double getDouble()
{
	double number;
	char c;
	while (1)
	{
		if (!scanf_s("%lf", &number) || INT_MAX < number || getchar() != '\n')
		{
			while ((c = getchar()) != '\n' && c != EOF);
		}
		else return number;

		printf_s("Необходимо ввести число.\nПовторите ввод: ");
	}
}

int factorial(int n)
{
	if (n == 1) return 1;
	else return factorial(n - 1) * n;
}

void cycle(double x, double e)				
{
	int n = 1, fact = 0;
	double sum = 0;

	while (1)
	{
		fact = 2 * n - 1;
		sum += powl(-1, n - 1) * powl(x, 2 * n) / factorial(fact);
		if (fabs(sum - sin(x)) < e)
		{
			double ans = fabs(sum - sin(x));
			printf("Погрешность : %lf\n", ans);
			break;
		}
			
		n++;
	}

	printf("Синус : %lf\n", sin(x));
	printf("Правая часть : %lf\n", sum);
	printf("При n : %d\n", n);
}

int main()
{
	
	double e = 0, x = 0;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Введите X : ");
	x = getDouble();
	printf("Введите E : ");
	while (e <= 0) e = getDouble();

	cycle(x, e);

    return 0;
}
