#include "stdafx.h"
#include <windows.h>

int main()
{
	int b = 10, k = 20, t = 200;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	for (int i = 0; i <= 10; i++)
		for (int j = 0; j <= 20; j++)
			for (int a = 0; a <= 200; a++)
			{
				if (((20 * i) + (10 * j) + a == 200) && (i + j + a == 100)) printf("Быков : %d , коров : %d, телят : %d \n", i, j, a);
			}

    return 0;
}
