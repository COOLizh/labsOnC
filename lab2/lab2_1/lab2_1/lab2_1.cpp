#include "stdafx.h"
#include <windows.h>
#include <limits.h>

float getDouble()
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
	}
}

int getInt()
{
	int number = 0;
	char c;
	while (number < 1 || number > 6)
	{
		if (!scanf_s("%d", &number) || getchar() != '\n')
		{
			while ((c = getchar()) != '\n' && c != EOF);
		}
		else
			return number;
	}
}

double enter()
{
	double money = 0;

	printf("-----------------------------------------------------\n");
	
	while (money <= 0 || INT_MAX < money)
	{
		printf("Введите сумму в белорусских рублях : ");
		money = getDouble();
	}

	return money;
}

void usd(double cash)
{
	if (cash == 0) printf("Введите сначала сумму выбрав пункт 1 в главном меню\n");
	else
	{
		printf("-----------------------------------------------------\n");
		printf("Ваша сумма в долларах : %f\nв евро : %f\nв рос.рублях : %f\n", cash / 1.948, cash / 2.398, cash / 0.0339);
	}
}

void benefit(double cash)
{
	double usd = 0, eur = 0, rubl = 0;

	usd = (cash / 1.948) - (cash / 1.969);
	eur = (cash / 2.398) - (cash / 2.422);
	rubl = (cash / 0.0339) - (cash / 0.0354);

	printf("-----------------------------------------------------\n");
	if (cash == 0) printf("Ваш баланс = 0, пожалуйста, выберте пункт (1.)Ввод денежной суммы в белорусских рублях.) в главном меню.\n");
	else
	{
		printf("Прибыль от продажи долларов : %f долларов\n", usd);
		printf("Прибыль от продажи евро : %f евро\n", eur);
		printf("Прибыль от продажи рос.рублей : %f рублей\n", rubl);

		rubl = rubl * 0.0176;
		eur = eur * 1.23;

		printf("Самая прибыльная валюта для банка : ");
		if (usd > rubl && usd > eur) printf("доллары\n");
		else if (eur > rubl && eur > usd) printf("евро\n");
		else printf("рос. рубли\n");
	}
}

void exchange_rates()
{
	printf("-----------------------------------------------------\n");
	printf("________________________________________________________________\n");
	printf("Валюта:\t\tПокупка:\tПродажа:\t\tНоминал:\n");
	printf("Рос.рубль\t3.39\t\t3.54\t\t\t100\n");
	printf("Доллар\t\t1.948\t\t1.969\t\t\t1\n");
	printf("Евро\t\t2.398\t\t2.422\t\t\t1\n");
	printf("________________________________________________________________\n\n");
}

void info()
{
	printf("-----------------------------------------------------\n");
	printf("Навзание : Приорбанк.\nТип : открытое акционерное общество\nГод основания : 1989\nЛицензия : № 12 от 06.05.2013\n");
	printf("Телефон : +37517 289 92 92\nПочта : priorbank@gmail.com\n");
}

int main()
{
	int choice = 0;
	double cash = 0;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (choice < 1 || choice > 6 || INT_MAX > choice)
	{
		
		printf("-----------------------------------------------------\n");
		printf("Выберете действие :\n1.)Ввод денежной суммы в белорусских рублях.\n2.)Вывод суммы в долларах, евро и рос.рублях\n3.)Вывод курсов валют.\n4.)Определения выгодной для банка сделки\n5.)Информация о банке\n6.)Выход. : ");

		choice = getInt();

		if (choice == 1)
			cash = enter();
		else if (choice == 2)
			usd(cash);
		else if (choice == 3)
			exchange_rates();
		else if (choice == 4)
			benefit(cash);
		else if (choice == 5)
			info();
		else if (choice == 6)
			break;
	}

    return 0;
}
