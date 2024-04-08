#include <iostream>
#include <iomanip>
#include <limits>
#include <locale.h>
#include <cmath>
#include "functions.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int o = -1;

	do

	{
		cout << "Выберите действие, совершаемое над функцией, где:\n1 - поиск корня F(x) = 0 на отрезке\n2 - поиск экстремумов на отрезке\n0 - выйти из программы" << endl;
		while (!(cin >> o))
		{
			cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		switch (o)
		{
		case 0:
			cout << "Выполнение программы завершено" << endl;
			break;
		case 1:
			cout << "Вы выбрали поиск корня F(x) = 0 на отрезке" << endl;
			searchRoot();
			break;
		case 2:
			cout << "Вы выбрали поиск экстремумов на отрезке" << endl;
			searchExtremums();
			break;
		default:
			cout << "Неверный выбор действия" << endl;
		}
	} while (o != 0);

	return 0;
}