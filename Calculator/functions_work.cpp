#include <iostream>
#include <iomanip>
#include <limits>
#include <locale.h>
#include <cmath>
#include "functions.h"
using namespace std;


void work_function()
{
	int oo = -1;

	do

	{
		cout << "Выберите действие, совершаемое над функцией, где:\n"
			<< "1 - Вычисление определённого интеграла на отрезке;\n"
			<< "2 - Построение графика функции;\n"
			<< "3 - поиск корня F(x) = 0 на отрезке;\n"
			<< "4 - поиск экстремумов на отрезке;\n"
			<< "0 - выйти из программы" << endl;
		while (!(cin >> oo))
		{
			cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		switch (oo)
		{
		case 0:
			cout << "Выполнение программы завершено" << endl;
			break;
		case 1:
			cout << "Вы выбрали вычисление определённого интеграла на отрезке" << endl;
			integral();
			break;
		case 2:
			cout << "Вы выбрали построение графика функции" << endl;

			break;
		case 3:
			cout << "Вы выбрали поиск корня F(x) = 0 на отрезке" << endl;
			searchRoot();
			break;
		case 4:
			cout << "Вы выбрали поиск экстремумов на отрезке" << endl;
			searchExtremums();
			break;
		default:
			cout << "Неверный выбор действия" << endl;
		}
	} while (oo != 0);
}



void integral()
{
	int x = 0;

	cout << "Введите нижний предел интегрирования:\n";
	double integration_range1;
	while (!(cin >> integration_range1))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "Введите верхний предел интегрирования:\n";
	double integration_range2;
	while (!(cin >> integration_range2))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	function(x, integration_range1, integration_range2);
}

double polinom_cin(double x, double* coefficient, int n)
{
	double result = 0;
	{
		for (int i = 1; i <= n; i++)
		{
			result += coefficient[i] * pow(x, i);
		}
	}
	return result + coefficient[0];
}

void polinom(double integration_range1, double integration_range2)
{
	cout << "Вы выбрали функцию типа: полином n - ой степени - a0 + a1*x + a2*x^2 + ... + aN*x^N" << endl;
	cout << "Необходимо заполнить маску полинома, введите его свободный член и максимальную степень" << endl;

	double a0, n;

	cout << "a0 = ";

	while (!(cin >> a0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "n = ";

	while (!(cin >> n) || n == 0)
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "Введите коэффициенты, соответствующие каждой степени X" << endl;

	double* coefficient = new double[abs(n)];
	coefficient[0] = a0;

	for (int i = 1; i <= abs(n); i++)
	{
		cout << "a" << i << " = "; cin >> coefficient[i];
	}

	double step;
	int N = 10000;
	int k;
	step = (integration_range2 - integration_range1) / N;

	double result = polinom_cin(integration_range1, coefficient, n) + polinom_cin(integration_range2, coefficient, n);
	for (int i = 1; i <= N - 1; i++)
	{
		k = 2 + (i % 2) * 2;
		result += polinom_cin(integration_range1 + i * step, coefficient, n) * k;
	}
	result *= step / 3;
	cout << "Результат вычисления интеграла:  " << result;
}



double degree_cin(double x, double a0, double b0, double c0)
{
	return a0 * pow(x, b0) + c0;
}

void degree(double integration_range1, double integration_range2)
{
	cout << "Вы выбрали функцию типа: степенная функция: a0*x^b0 + c0" << endl;
	cout << "Необходимо заполнить маску степенной функции, введите ее свободный член и множитель, степень X" << endl;

	double c0, b0, a0;

	cout << "c0 = ";

	while (!(cin >> c0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "a0 = ";

	while (!(cin >> a0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b0 = ";

	while (!(cin >> b0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double step;
	int N = 10000;
	int k;
	step = (integration_range2 - integration_range1) / N;

	double result = degree_cin(integration_range1, a0, b0, c0) + degree_cin(integration_range2, a0, b0, c0);
	for (int i = 1; i <= N - 1; i++)
	{
		k = 2 + (i % 2) * 2;
		result += degree_cin(integration_range1 + i * step, a0, b0, c0) * k;
	}
	result *= step / 3;
	cout << "Результат вычисления интеграла:  " << result;
}



double exponential_cin(double x, double a0, double b0, double c0, double d0)
{
	return a0 * pow(b0, c0 * x) + d0;
}

void exponential(double integration_range1, double integration_range2)
{

	cout << "Вы выбрали функцию типа: показательная функция: a0*b0^(c0*x) + d0" << endl;
	cout << "Необходимо заполнить маску показательной функции, введите ее свободный член, основание(a*b) и множитель показателя X" << endl;

	double d0, a0 = 0, b0 = 0, c0;

	cout << "d0 = ";

	while (!(cin >> d0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	while (a0 * b0 <= 0 || a0 * b0 == 1)
	{
		cout << "a0 = ";

		while (!(cin >> a0))
		{
			cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		cout << "b0 = ";

		while (!(cin >> b0))
		{
			cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	cout << "c0 = ";

	while (!(cin >> c0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double step;
	int N = 10000;
	int k;
	step = (integration_range2 - integration_range1) / N;

	double result = exponential_cin(integration_range1, a0, b0, c0, d0) + exponential_cin(integration_range2, a0, b0, c0, d0);
	for (int i = 1; i <= N - 1; i++)
	{
		k = 2 + (i % 2) * 2;
		result += exponential_cin(integration_range1 + i * step, a0, b0, c0, d0) * k;
	}
	result *= step / 3;
	cout << "Результат вычисления интеграла:  " << result;
}



double logarithm_cin(double x, double a0, double b0, double c0)
{
	return a0 * log(b0 * x) + c0;
}

void logarithm(double integration_range1, double integration_range2)
{
	cout << "Вы выбрали функцию типа: логарифмическая функция: a0*ln(b0*x) + c0" << endl;
	cout << "Необходимо заполнить маску логарифмической функции, введите ее свободный член, множитель логарифма и множитель X аргумента логарифма" << endl;

	double c0, a0, b0;

	cout << "c0 = ";

	while (!(cin >> c0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "a0 = ";

	while (!(cin >> a0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b0 = ";

	while (!(cin >> b0) || b0 <= 0)
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double step;
	int N = 10000;
	int k;
	step = (integration_range2 - integration_range1) / N;

	double result = logarithm_cin(integration_range1, a0, b0, c0) + logarithm_cin(integration_range2, a0, b0, c0);
	for (int i = 1; i <= N - 1; i++)
	{
		k = 2 + (i % 2) * 2;
		result += logarithm_cin(integration_range1 + i * step, a0, b0, c0) * k;
	}
	result *= step / 3;
	cout << "Результат вычисления интеграла:  " << result;
}



double sinus_cin(double x, double a0, double b0, double c0, double d0)
{
	return a0 * sin(b0 * x + c0) + d0;
}

void sinus(double integration_range1, double integration_range2)
{
	cout << "Вы выбрали функцию типа: синусоида: a0*sin(b0*x + c0) + d0" << endl;
	cout << "Необходимо заполнить маску синусоиды, введите ее свободный член, множитель sin - уса, множитель X аргумента sin - уса, слагаемое аргумента sin - уса" << endl;

	double a0, b0, c0, d0;

	cout << "d0 = ";

	while (!(cin >> d0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "a0 = ";

	while (!(cin >> a0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b0 = ";

	while (!(cin >> b0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "c0 = ";

	while (!(cin >> c0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double step;
	int N = 10000;
	int k;
	step = (integration_range2 - integration_range1) / N;

	double result = sinus_cin(integration_range1, a0, b0, c0, d0) + sinus_cin(integration_range2, a0, b0, c0, d0);
	for (int i = 1; i <= N - 1; i++)
	{
		k = 2 + (i % 2) * 2;
		result += sinus_cin(integration_range1 + i * step, a0, b0, c0, d0) * k;
	}
	result *= step / 3;
	cout << "Результат вычисления интеграла:  " << result;

}



double cosinus_cin(double x, double a0, double b0, double c0, double d0)
{
	return a0 * cos(b0 * x + c0) + d0;
}

void cosinus(double integration_range1, double integration_range2)
{
	cout << "Вы выбрали функцию типа: косинусоида: a0* cos(b0 * x + c0) + d0;" << endl;
	cout << "Необходимо заполнить маску синусоиды, введите ее свободный член, множитель cos - уса, множитель X аргумента cos - инуса, слагаемое аргумента cos - инуса" << endl;

	double a0, b0, c0, d0;

	cout << "d0 = ";

	while (!(cin >> d0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "a0 = ";

	while (!(cin >> a0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b0 = ";

	while (!(cin >> b0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "c0 = ";

	while (!(cin >> c0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double step;
	int N = 10000;
	int k;
	step = (integration_range2 - integration_range1) / N;

	double result = cosinus_cin(integration_range1, a0, b0, c0, d0) + cosinus_cin(integration_range2, a0, b0, c0, d0);
	for (int i = 1; i <= N - 1; i++)
	{
		k = 2 + (i % 2) * 2;
		result += cosinus_cin(integration_range1 + i * step, a0, b0, c0, d0) * k;
	}
	result *= step / 3;
	cout << "Результат вычисления интеграла:  " << result;

}

void function(double x, double integration_range1, double integration_range2)
{
	int o1;

	do
	{
		cout << "Выберите функцию, с которой хотите работать, где:\n1 - полином n - ой степени: a0 + a1*x + a2*x^2 + ... + aN*x^N\n2 - степенная функция: a0*x^b0 + c0\n3 - показательная функция: a0*b0^(c0*x) + d0\n4 - логарифмическая функция: a0*ln(b0*x) + c0\n5 - синусоида: a0*sin(b0*x + c0) + d0\n6 - косинусоида: a0*cos(b0*x + c0) + d0\n0 - закрыть меню выбора функции" << endl;
		while (!(cin >> o1))
		{
			cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (o1)
		{
		case 0:
			cout << "Меню выбора функции закрыто" << endl;
			break;
		case 1:
			polinom(integration_range1, integration_range2);
			break;
		case 2:
			degree(integration_range1, integration_range2);
			break;
		case 3:
			exponential(integration_range1, integration_range2);
			break;
		case 4:
			logarithm(integration_range1, integration_range2);
			break;
		case 5:
			sinus(integration_range1, integration_range2);
			break;
		case 6:
			cosinus(integration_range1, integration_range2);
			break;
		}
	} while (o1 != 0);
}


double func11(double x, double* coefficient, int n, double a0)
{
	double result = 0;
	{
		for (int i = 1; i <= n; i++)
		{
			result += coefficient[i] * pow(x, i);
		}
	}
	return result + coefficient[0];
}

void Polinom1()
{
	cout << "Вы выбрали функцию типа: полином n - ой степени - a0 + a1*x + a2*x^2 + ... + aN*x^N" << endl;
	cout << "Необходимо заполнить маску полинома, введите его свободный член и максимальную степень" << endl;

	double a0, n;

	cout << "a0 = ";

	while (!(cin >> a0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "n = ";

	while (!(cin >> n) || n == 0)
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "Введите коэффициенты, соответствующие каждой степени X" << endl;

	double* coefficient = new double[abs(n)];
	coefficient[0] = a0;

	for (int i = 1; i <= abs(n); i++)
	{
		cout << "a" << i << " = "; cin >> coefficient[i];
	}

	double a = 0.0, b = -1, c;

	cout << "Введите отрезок [a, b]" << endl;

	cout << "a = ";

	while (!(cin >> a))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b = ";

	while (!(cin >> b) || b <= a)
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int k = 0;
	double b1 = b;

	while (abs(a - b) >= 0.0000000000000001)
	{
		c = (a + b) / 2.0;

		//cout << "c = " << c << endl;

		/*if ((findRootPolinom(a, coefficient, n, a0) * findRootPolinom(b, coefficient, n, a0)) > 0)
		{
			cout << "Некорректный интервал для поиска корня, т.к. на концах отрезка функция имеет одинаковые знаковые значения" << endl;
			return NAN;
		}*/

		if (func11(c, coefficient, n, a0) == 0.0)
		{
			cout << "Корень найден: " << c << endl;
			break;
		}
		else if (func11(a, coefficient, n, a0) * func11(c, coefficient, n, a0) < 0)
		{
			b = c;
		}
		else
		{
			a = c;
		}

		k++;

		if (k == 30)
		{
			if ((abs(b1 - c) > 0.001))
			{
				cout << "Корень найден: " << c << endl;
			}
			else
			{
				cout << "На данном отрезке нет корня F(x) или подобран неверный интервал, на котором функция имеет одинаковые знаковые значения" << endl;
			}
			break;
		}
	}
}

double func12(double a0, double b0, double c0, double x)
{
	return a0 * pow(x, b0) + c0;
}

void Degrees1()
{
	cout << "Вы выбрали функцию типа: степенная функция: a0*x^b0 + c0" << endl;
	cout << "Необходимо заполнить маску степенной функции, введите ее свободный член и множитель, степень X" << endl;

	double c0, b0, a0;

	cout << "c0 = ";

	while (!(cin >> c0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "a0 = ";

	while (!(cin >> a0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b0 = ";

	while (!(cin >> b0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double a = 0.0, b = -1, c;

	cout << "Введите отрезок [a, b]" << endl;

	cout << "a = ";

	while (!(cin >> a))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b = ";

	while (!(cin >> b) || b <= a)
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int k = 0;

	double b1 = b;

	while (abs(a - b) >= 0.0000000000000001)
	{
		c = (a + b) / 2.0;

		//cout << "Текущее с = " << c << endl;

		/*if ((findRootDegrees(a0, b0, c0, a) * findRootDegrees(a0, b0, c0, b)) >= 0)
		{
			cout << "Некорректный интервал для поиска корня, т.к. на концах отрезка функция имеет одинаковые знаковые значения" << endl;
			return NAN;
		}*/
		if (func12(a0, b0, c0, c) == 0.0)
		{
			cout << "Корень найден: " << c << endl;
			break;
		}
		else if (func12(a0, b0, c0, a) * func12(a0, b0, c0, c) < 0)
		{
			b = c;
		}
		else
		{
			a = c;
		}

		k++;

		if (k == 30)
		{
			//cout << "k = " << k << endl;
			if ((abs(b1 - c) > 0.001))
			{
				cout << "Корень найден: " << c << endl;
			}
			else
			{
				cout << "На данном отрезке нет корня F(x) или подобран неверный интервал, на котором функция имеет одинаковые знаковые значения" << endl;
			}
			break;
		}
	}
}

double func13(double a0, double b0, double c0, double x, double d0)
{
	return a0 * pow(b0, c0 * x) + d0;
}

void Exponential1()
{
	cout << "Вы выбрали функцию типа: показательная функция: a0*b0^(c0*x) + d0" << endl;
	cout << "Необходимо заполнить маску показательной функции, введите ее свободный член, основание(a*b) и множитель показателя X" << endl;

	double d0, a0 = 0, b0 = 0, c0;

	cout << "d0 = ";

	while (!(cin >> d0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	while (a0 * b0 <= 0 || a0 * b0 == 1)
	{
		cout << "a0 = ";

		while (!(cin >> a0))
		{
			cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		cout << "b0 = ";

		while (!(cin >> b0))
		{
			cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	cout << "c0 = ";

	while (!(cin >> c0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double a = 0.0, b = -1, c;

	cout << "Введите отрезок [a, b]" << endl;

	cout << "a = ";

	while (!(cin >> a))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b = ";

	while (!(cin >> b) || b <= a)
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int k = 0;
	double b1 = b;

	while (abs(a - b) >= 0.00000001)
	{
		c = (a + b) / 2.0;

		//cout << "c = " << c << endl;

		/*if ((findRootPolinom(a, coefficient, n, a0) * findRootPolinom(b, coefficient, n, a0)) > 0)
		{
			cout << "Некорректный интервал для поиска корня, т.к. на концах отрезка функция имеет одинаковые знаковые значения" << endl;
			return NAN;
		}*/

		if (func13(a0, b0, c0, c, d0) == 0.0)
		{
			cout << "Корень найден: " << c << endl;
			break;
		}
		else if (func13(a0, b0, c0, a, d0) * func13(a0, b0, c0, c, d0) < 0)
		{
			b = c;
		}
		else
		{
			a = c;
		}

		k++;

		if (k == 25)
		{
			if ((abs(b1 - c) > 0.001))
			{
				cout << "Корень найден: " << c << endl;
			}
			else
			{
				cout << "На данном отрезке нет корня F(x) или подобран неверный интервал, на котором функция имеет одинаковые знаковые значения" << endl;
			}
			break;
		}
	}
}

double func14(double a0, double b0, double c0, double x)
{
	return a0 * log(b0 * x) + c0;
}

void Logarithm1()
{
	cout << "Вы выбрали функцию типа: логарифмическая функция: a0*ln(b0*x) + c0" << endl;
	cout << "Необходимо заполнить маску логарифмической функции, введите ее свободный член, множитель логарифма и множитель X аргумента логарифма" << endl;

	double c0, a0, b0;

	cout << "c0 = ";

	while (!(cin >> c0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "a0 = ";

	while (!(cin >> a0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b0 = ";

	while (!(cin >> b0) || b0 <= 0)
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double a = 0.0, b = -1, c;

	cout << "Введите отрезок [a, b]" << endl;

	cout << "a = ";

	while (!(cin >> a) || a <= 0)
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b = ";

	while (!(cin >> b) || b <= a)
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int k = 0;
	double b1 = b;
	//double count = (log2((abs(b - a))) / 0.0001) + 1;
	//cout << "Необходимое число итераций = " << count << endl;

	while (abs(a - b) >= 0.00000000001)
	{
		c = (a + b) / 2.0;

		/*if ((c * b0 <= 0))
		{
			cout << "Неверно введен множитель X аргумента логарифма b0" << endl;
			return NAN;
		}*/

		//cout << "c = " << c << endl;

		/*if ((findRootPolinom(a, coefficient, n, a0) * findRootPolinom(b, coefficient, n, a0)) > 0)
		{
			cout << "Некорректный интервал для поиска корня, т.к. на концах отрезка функция имеет одинаковые знаковые значения" << endl;
			return NAN;
		}*/

		if (func14(a0, b0, c0, c) == 0.0)
		{
			cout << "Корень найден: " << c << endl;
			break;
		}
		else if (func14(a0, b0, c0, a) * func14(a0, b0, c0, c) < 0)
		{
			b = c;
		}
		else
		{
			a = c;
		}

		k++;

		if (k == 30)
		{
			if ((abs(b1 - c) > 0.001))
			{
				cout << "Корень найден: " << c << endl;
			}
			else
			{
				cout << "На данном отрезке нет корня F(x) или подобран неверный интервал, на котором функция имеет одинаковые знаковые значения" << endl;
			}
			break;
		}
	}
}

double func15(double a0, double b0, double c0, double d0, double x)
{
	return a0 * sin(b0 * x + c0) + d0;
}

void SineWave1()
{
	cout << "Вы выбрали функцию типа: синусоида: a0*sin(b0*x + c0) + d0" << endl;
	cout << "Необходимо заполнить маску синусоиды, введите ее свободный член, множитель sin - уса, множитель X аргумента sin - уса, слагаемое аргумента sin - уса" << endl;

	double a0, b0, c0, d0;

	cout << "d0 = ";

	while (!(cin >> d0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "a0 = ";

	while (!(cin >> a0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b0 = ";

	while (!(cin >> b0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "c0 = ";

	while (!(cin >> c0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double a = 0.0, b = -1, c;

	cout << "Введите отрезок [a, b]" << endl;

	cout << "a = ";

	while (!(cin >> a))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b = ";

	while (!(cin >> b))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int k = 0;
	double b1 = b;

	while (abs(a - b) >= 0.00000000001)
	{
		c = (a + b) / 2.0;

		//cout << "c = " << c << endl;

		/*if ((findRootPolinom(a, coefficient, n, a0) * findRootPolinom(b, coefficient, n, a0)) > 0)
		{
			cout << "Некорректный интервал для поиска корня, т.к. на концах отрезка функция имеет одинаковые знаковые значения" << endl;
			return NAN;
		}*/

		if (func15(a0, b0, c0, d0, c) == 0.0)
		{
			cout << "Корень найден: " << c << endl;
			break;
		}
		else if (func15(a0, b0, c0, d0, a) * func15(a0, b0, c0, d0, c) < 0)
		{
			b = c;
		}
		else
		{
			a = c;
		}

		k++;

		if (k == 30)
		{
			if ((abs(b1 - c) > 0.001))
			{
				cout << "Корень найден: " << c << endl;
			}
			else
			{
				cout << "На данном отрезке нет корня F(x) или подобран неверный интервал, на котором функция имеет одинаковые знаковые значения" << endl;
			}
			break;
		}
	}
}

double func16(double a0, double b0, double c0, double d0, double x)
{
	return a0 * cos(b0 * x + c0) + d0;
}

void CosineWave1()
{
	cout << "Вы выбрали функцию типа: косинусоида: a0* cos(b0 * x + c0) + d0;" << endl;
	cout << "Необходимо заполнить маску синусоиды, введите ее свободный член, множитель cos - уса, множитель X аргумента cos - инуса, слагаемое аргумента cos - инуса" << endl;

	double a0, b0, c0, d0;

	cout << "d0 = ";

	while (!(cin >> d0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "a0 = ";

	while (!(cin >> a0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b0 = ";

	while (!(cin >> b0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "c0 = ";

	while (!(cin >> c0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double a = 0.0, b = -1, c;

	cout << "Введите отрезок [a, b]" << endl;

	cout << "a = ";

	while (!(cin >> a))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b = ";

	while (!(cin >> b))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int k = 0;
	double b1 = b;

	while (abs(a - b) >= 0.00000000001)
	{
		c = (a + b) / 2.0;

		//cout << "c = " << c << endl;

		/*if ((findRootPolinom(a, coefficient, n, a0) * findRootPolinom(b, coefficient, n, a0)) > 0)
		{
			cout << "Некорректный интервал для поиска корня, т.к. на концах отрезка функция имеет одинаковые знаковые значения" << endl;
			return NAN;
		}*/

		if (func16(a0, b0, c0, d0, c) == 0.0)
		{
			cout << "Корень найден: " << c << endl;
			break;
		}
		else if (func16(a0, b0, c0, d0, a) * func16(a0, b0, c0, d0, c) < 0)
		{
			b = c;
		}
		else
		{
			a = c;
		}

		k++;

		if (k == 30)
		{
			if ((abs(b1 - c) > 0.001))
			{
				cout << "Корень найден: " << c << endl;
			}
			else
			{
				cout << "На данном отрезке нет корня F(x) или подобран неверный интервал, на котором функция имеет одинаковые знаковые значения" << endl;
			}
			break;
		}
	}
}

void searchRoot()
{
	int o1;

	do
	{
		cout << "Выберите функцию, с которой хотите работать, где:\n1 - полином n - ой степени: a0 + a1*x + a2*x^2 + ... + aN*x^N\n2 - степенная функция: a0*x^b0 + c0\n3 - показательная функция: a0*b0^(c0*x) + d0\n4 - логарифмическая функция: a0*ln(b0*x) + c0\n5 - синусоида: a0*sin(b0*x + c0) + d0\n6 - косинусоида: a0*cos(b0*x + c0) + d0\n0 - закрыть меню выбора функции" << endl;
		while (!(cin >> o1))
		{
			cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (o1)
		{
		case 0:
			cout << "Меню выбора функции закрыто" << endl;
			break;
		case 1:
			Polinom1();
			break;
		case 2:
			Degrees1();
			break;
		case 3:
			Exponential1();
			break;
		case 4:
			Logarithm1();
			break;
		case 5:
			SineWave1();
			break;
		case 6:
			CosineWave1();
			break;
		}
	} while (o1 != 0);
}

double func21(double x, double* coefficient, int n, double a0)
{
	double result = 0;
	{
		for (int i = 1; i <= n; i++)
		{
			result += coefficient[i] * pow(x, i);
		}
	}
	return result + coefficient[0];
}

double findMinExtremumsPolinom2(double a, double b, double* coefficient, int n, double a0)
{
	double x1, x2;
	double delta = 0.00000000001 / 2.0;

	while (abs(b - a) > 0.00000000001)
	{
		x1 = (a + b - delta) / 2.0;
		x2 = (a + b + delta) / 2.0;

		if (func21(x1, coefficient, n, a0) < func21(x2, coefficient, n, a0))
		{
			b = x2;
		}
		else
		{
			a = x1;
		}
	}

	return (a + b) / 2.0;
}

double findMaxExtremumsPolinom2(double a, double b, double* coefficient, int n, double a0)
{
	double x1, x2;
	double delta = 0.00000000001 / 2.0;

	while (abs(b - a) > 0.00000000001)
	{
		x1 = (a + b - delta) / 2.0;
		x2 = (a + b + delta) / 2.0;

		if (func21(x1, coefficient, n, a0) > func21(x2, coefficient, n, a0))
		{
			b = x2;
		}
		else
		{
			a = x1;
		}
	}

	return (a + b) / 2.0;
}

void Polinom2()
{
	cout << "Вы выбрали функцию типа: полином n - ой степени - a0 + a1*x + a2*x^2 + ... + aN*x^N" << endl;
	cout << "Необходимо заполнить маску полинома, введите его свободный член и максимальную степень" << endl;

	double a0, n;

	cout << "a0 = ";

	while (!(cin >> a0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "n = ";

	while (!(cin >> n) || n == 0)
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "Введите коэффициенты, соответствующие каждой степени X" << endl;

	double* coefficient = new double[abs(n)];
	coefficient[0] = a0;

	for (int i = 1; i <= abs(n); i++)
	{
		cout << "a" << i << " = "; cin >> coefficient[i];
	}

	double a = 0.0, b = -1;

	cout << "Введите отрезок [a, b]" << endl;

	cout << "a = ";

	while (!(cin >> a))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b = ";

	while (!(cin >> b) || b <= a)
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double minDot = findMinExtremumsPolinom2(a, b, coefficient, n, a0);
	double minValue = func21(minDot, coefficient, n, a0);

	double maxDot = findMaxExtremumsPolinom2(a, b, coefficient, n, a0);
	double maxValue = func21(maxDot, coefficient, n, a0);

	cout << "Минимум функции: " << minValue << " достигается в точке " << (minDot) << endl;
	cout << "Максимум функции: " << maxValue << " достигается в точке " << maxDot << endl;
}

double func22(double a0, double b0, double c0, double x)
{
	return a0 * pow(x, b0) + c0;
}

double findMinExtremumsDegrees2(double a, double b, double a0, double b0, double c0)
{
	double x1, x2;
	double delta = 0.00000000001 / 2.0;

	while (abs(b - a) > 0.00000000001)
	{
		x1 = (a + b - delta) / 2.0;
		x2 = (a + b + delta) / 2.0;

		if (func22(a0, b0, c0, x1) < func22(a0, b0, c0, x2))
		{
			b = x2;
		}
		else
		{
			a = x1;
		}
	}

	return (a + b) / 2.0;
}

double findMaxExtremumsDegrees2(double a, double b, double a0, double b0, double c0)
{
	double x1, x2;
	double delta = 0.0000000000000001 / 2.0;

	while (abs(b - a) > 0.0000000000000001)
	{
		x1 = (a + b - delta) / 2.0;
		x2 = (a + b + delta) / 2.0;

		if (func22(a0, b0, c0, x1) > func22(a0, b0, c0, x2))
		{
			b = x2;
		}
		else
		{
			a = x1;
		}
	}

	return (a + b) / 2.0;
}

void Degrees2()
{
	cout << "Вы выбрали функцию типа: степенная функция: a0*x^b0 + c0" << endl;
	cout << "Необходимо заполнить маску степенной функции, введите ее свободный член и множитель, степень X" << endl;

	double c0, b0, a0;

	cout << "c0 = ";

	while (!(cin >> c0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "a0 = ";

	while (!(cin >> a0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b0 = ";

	while (!(cin >> b0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double a = 0.0, b = -1;

	cout << "Введите отрезок [a, b]" << endl;

	cout << "a = ";

	while (!(cin >> a))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b = ";

	while (!(cin >> b) || b <= a)
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double minDot = findMinExtremumsDegrees2(a, b, a0, b0, c0);
	double minValue = func22(a0, b0, c0, minDot);

	double maxDot = findMaxExtremumsDegrees2(a, b, a0, b0, c0);
	double maxValue = func22(a0, b0, c0, maxDot);

	cout << "Минимум функции: " << minValue << " достигается в точке " << (minDot) << endl;
	cout << "Максимум функции: " << maxValue << " достигается в точке " << maxDot << endl;
}

double func23(double a0, double b0, double c0, double x, double d0)
{
	return a0 * pow(b0, c0 * x) + d0;
}

double findMinExrtremumsExponential2(double a0, double b0, double c0, double d0, double a, double b)
{
	double x1, x2;
	double delta = 0.00000000001 / 2.0;

	while (abs(b - a) > 0.00000000001)
	{
		x1 = (a + b - delta) / 2.0;
		x2 = (a + b + delta) / 2.0;

		if (func23(a0, b0, c0, x1, d0) < func23(a0, b0, c0, x2, d0))
		{
			b = x2;
		}
		else
		{
			a = x1;
		}
	}

	return (a + b) / 2.0;
}

double findMaxExrtremumsExponential2(double a0, double b0, double c0, double d0, double a, double b)
{
	double x1, x2;
	double delta = 0.0000000000000001 / 2.0;

	while (abs(b - a) > 0.0000000000000001)
	{
		x1 = (a + b - delta) / 2.0;
		x2 = (a + b + delta) / 2.0;

		if (func23(a0, b0, c0, x1, d0) > func23(a0, b0, c0, x2, d0))
		{
			b = x2;
		}
		else
		{
			a = x1;
		}
	}

	return (a + b) / 2.0;
}

void Exponential2()
{
	cout << "Вы выбрали функцию типа: показательная функция: a0*b0^(c0*x) + d0" << endl;
	cout << "Необходимо заполнить маску показательной функции, введите ее свободный член, основание(a*b) и множитель показателя X" << endl;

	double d0, a0 = 0, b0 = 0, c0;

	cout << "d0 = ";

	while (!(cin >> d0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	while (a0 * b0 <= 0 || a0 * b0 == 1)
	{
		cout << "a0 = ";

		while (!(cin >> a0))
		{
			cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		cout << "b0 = ";

		while (!(cin >> b0))
		{
			cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	cout << "c0 = ";

	while (!(cin >> c0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double a = 0.0, b = -1;

	cout << "Введите отрезок [a, b]" << endl;

	cout << "a = ";

	while (!(cin >> a))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b = ";

	while (!(cin >> b) || b <= a)
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double minDot = findMinExrtremumsExponential2(a0, b0, c0, d0, a, b);
	double minValue = func23(a0, b0, c0, minDot, d0);

	double maxDot = findMaxExrtremumsExponential2(a0, b0, c0, d0, a, b);
	double maxValue = func23(a0, b0, c0, maxDot, d0);

	cout << "Минимум функции: " << minValue << " достигается в точке " << (minDot) << endl;
	cout << "Максимум функции: " << maxValue << " достигается в точке " << maxDot << endl;
}

double func24(double a0, double b0, double c0, double x)
{
	return a0 * log(b0 * x) + c0;
}

double findMinExrtremumsLogarithm2(double a0, double b0, double c0, double a, double b)
{
	double x1, x2;
	double delta = 0.00000000001 / 2.0;

	while (abs(b - a) > 0.00000000001)
	{
		x1 = (a + b - delta) / 2.0;
		x2 = (a + b + delta) / 2.0;

		if (func24(a0, b0, c0, x1) < func24(a0, b0, c0, x2))
		{
			b = x2;
		}
		else
		{
			a = x1;
		}
	}

	return (a + b) / 2.0;
}

double findMaxExrtremumsLogarithm2(double a0, double b0, double c0, double a, double b)
{
	double x1, x2;
	double delta = 0.0000000000000001 / 2.0;

	while (abs(b - a) > 0.0000000000000001)
	{
		x1 = (a + b - delta) / 2.0;
		x2 = (a + b + delta) / 2.0;

		if (func24(a0, b0, c0, x1) > func24(a0, b0, c0, x2))
		{
			b = x2;
		}
		else
		{
			a = x1;
		}
	}

	return (a + b) / 2.0;
}

void Logarithm2()
{
	cout << "Вы выбрали функцию типа: логарифмическая функция: a0*ln(b0*x) + c0" << endl;
	cout << "Необходимо заполнить маску логарифмической функции, введите ее свободный член, множитель логарифма и множитель X аргумента логарифма" << endl;

	double c0, a0, b0;

	cout << "c0 = ";

	while (!(cin >> c0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "a0 = ";

	while (!(cin >> a0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b0 = ";

	while (!(cin >> b0) || b0 <= 0)
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double a = 0.0, b = -1, c;

	cout << "Введите отрезок [a, b]" << endl;

	cout << "a = ";

	while (!(cin >> a) || a <= 0)
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b = ";

	while (!(cin >> b) || b <= a)
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double minDot = findMinExrtremumsLogarithm2(a0, b0, c0, a, b);
	double minValue = func24(a0, b0, c0, minDot);

	double maxDot = findMaxExrtremumsLogarithm2(a0, b0, c0, a, b);
	double maxValue = func24(a0, b0, c0, maxDot);

	cout << "Минимум функции: " << minValue << " достигается в точке " << (minDot) << endl;
	cout << "Максимум функции: " << maxValue << " достигается в точке " << maxDot << endl;
}

double func25(double a0, double b0, double c0, double d0, double x)
{
	//double pi = 3.14159265358979323846;
	//double result = (b0 * x + c0) * (pi / 180);

	/*if (result < -pi / 2 || result > pi / 2) {
		cerr << "Аргумент синуса вышел за допустимые пределы." << endl;
		return NAN;
	}*/

	return a0 * sin(b0 * x + c0) + d0;
}

double findMinExrtremumsSineWave2(double a0, double b0, double c0, double d0, double a, double b)
{
	double x1, x2;
	double delta = 0.00000000001 / 2.0;

	while (abs(b - a) > 0.00000000001)
	{
		x1 = (a + b - delta) / 2.0;
		x2 = (a + b + delta) / 2.0;

		if (func25(a0, b0, c0, d0, x1) < func25(a0, b0, c0, d0, x2))
		{
			b = x2;
		}
		else
		{
			a = x1;
		}
	}

	return (a + b) / 2.0;
}

double findMaxExrtremumsSineWave2(double a0, double b0, double c0, double d0, double a, double b)
{
	double x1, x2;
	double delta = 0.00000000001 / 2.0;

	while (abs(b - a) > 0.00000000001)
	{
		x1 = (a + b - delta) / 2.0;
		x2 = (a + b + delta) / 2.0;

		if (func25(a0, b0, c0, d0, x1) > func25(a0, b0, c0, d0, x2))
		{
			b = x2;
		}
		else
		{
			a = x1;
		}
	}

	return (a + b) / 2.0;
}

void SineWave2()
{
	cout << "Вы выбрали функцию типа: синусоида: a0*sin(b0*x + c0) + d0" << endl;
	cout << "Необходимо заполнить маску синусоиды, введите ее свободный член, множитель sin - уса, множитель X аргумента sin - уса, слагаемое аргумента sin - уса" << endl;

	double a0, b0, c0, d0;

	cout << "d0 = ";

	while (!(cin >> d0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "a0 = ";

	while (!(cin >> a0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b0 = ";

	while (!(cin >> b0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "c0 = ";

	while (!(cin >> c0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double a = 0.0, b = -1, c;

	cout << "Введите отрезок [a, b]" << endl;

	cout << "a = ";

	while (!(cin >> a))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b = ";

	while (!(cin >> b))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double minDot = findMinExrtremumsSineWave2(a0, b0, c0, d0, a, b);
	double minValue = func25(a0, b0, c0, d0, minDot);

	double maxDot = findMaxExrtremumsSineWave2(a0, b0, c0, d0, a, b);
	double maxValue = func25(a0, b0, c0, d0, maxDot);

	cout << "Минимум функции: " << minValue << " достигается в точке " << (minDot) << endl;
	cout << "Максимум функции: " << maxValue << " достигается в точке " << maxDot << endl;
}

double func26(double a0, double b0, double c0, double d0, double x)
{
	//double pi = 3.14159265358979323846;
	//double result = (b0 * x + c0) * (pi / 180);

	/*if (result < -pi / 2 || result > pi / 2) {
		cerr << "Аргумент синуса вышел за допустимые пределы." << endl;
		return NAN;
	}*/

	return a0 * cos(b0 * x + c0) + d0;
}

double findMinExrtremumsCosineWave2(double a0, double b0, double c0, double d0, double a, double b)
{
	double x1, x2;
	double delta = 0.00000000001 / 2.0;

	while (abs(b - a) > 0.00000000001)
	{
		x1 = (a + b - delta) / 2.0;
		x2 = (a + b + delta) / 2.0;

		if (func26(a0, b0, c0, d0, x1) < func26(a0, b0, c0, d0, x2))
		{
			b = x2;
		}
		else
		{
			a = x1;
		}
	}

	return (a + b) / 2.0;
}

double findMaxExrtremumsCosineWave2(double a0, double b0, double c0, double d0, double a, double b)
{
	double x1, x2;
	double delta = 0.00000000001 / 2.0;

	while (abs(b - a) > 0.00000000001)
	{
		x1 = (a + b - delta) / 2.0;
		x2 = (a + b + delta) / 2.0;

		if (func26(a0, b0, c0, d0, x1) > func26(a0, b0, c0, d0, x2))
		{
			b = x2;
		}
		else
		{
			a = x1;
		}
	}

	return (a + b) / 2.0;
}

void CosineWave2()
{
	cout << "Вы выбрали функцию типа: синусоида: a0*sin(b0*x + c0) + d0" << endl;
	cout << "Необходимо заполнить маску синусоиды, введите ее свободный член, множитель sin - уса, множитель X аргумента sin - уса, слагаемое аргумента sin - уса" << endl;

	double a0, b0, c0, d0;

	cout << "d0 = ";

	while (!(cin >> d0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "a0 = ";

	while (!(cin >> a0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b0 = ";

	while (!(cin >> b0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "c0 = ";

	while (!(cin >> c0))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректные число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double a = 0.0, b = -1, c;

	cout << "Введите отрезок [a, b]" << endl;

	cout << "a = ";

	while (!(cin >> a))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "b = ";

	while (!(cin >> b))
	{
		cout << "Некорректный ввод. Пожалуйста, введите корректное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	double minDot = findMinExrtremumsCosineWave2(a0, b0, c0, d0, a, b);
	double minValue = func26(a0, b0, c0, d0, minDot);

	double maxDot = findMaxExrtremumsCosineWave2(a0, b0, c0, d0, a, b);
	double maxValue = func26(a0, b0, c0, d0, maxDot);

	cout << "Минимум функции: " << minValue << " достигается в точке " << (minDot) << endl;
	cout << "Максимум функции: " << maxValue << " достигается в точке " << maxDot << endl;
}



void searchExtremums()
{
	int o1;

	do
	{
		cout << "Выберите функцию, с которой хотите работать, где:\n1 - полином n - ой степени: a0 + a1*x + a2*x^2 + ... + aN*x^N\n2 - степенная функция: a0*x^b0 + c0\n3 - показательная функция: a0*b0^(c0*x) + d0\n4 - логарифмическая функция: a0*ln(b0*x) + c0\n5 - синусоида: a0*sin(b0*x + c0) + d0\n6 - косинусоида: a0*cos(b0*x + c0) + d0\n0 - закрыть меню выбора функции" << endl;
		while (!(cin >> o1))
		{
			cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (o1)
		{
		case 0:
			cout << "Меню выбора функции закрыто" << endl;
			break;
		case 1:
			Polinom2();
			break;
		case 2:
			Degrees2();
			break;
		case 3:
			Exponential2();
			break;
		case 4:
			Logarithm2();
			break;
		case 5:
			SineWave2();
			break;
		case 6:
			CosineWave2();
			break;
		}
	} while (o1 != 0);
}
