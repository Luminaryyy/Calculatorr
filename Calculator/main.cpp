#include <iostream>
#include <iomanip>
#include <limits>
#include <locale.h>
#include <cmath>

#include "matrix.h"
#include "fraction.h"
#include "combinatorics_formulas.h"
#include "probability_and_math_statistic.h"
#include "functions.h"
#include "polinom.h"

using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");
	int o = -1;

	do {
		cout << "Выберите тип калькулятора, с которым хотите работать:\n1 - Матричный калькулятор;"
			<< "\n2 - Калькулятор обыкновенных дробей; \n3 - Калькулятор формул комбинаторики;"
			<< "\n4 - Калькулятор теории вероятности и математической статистики; \n5 - Калькулятор функций;"
			<< "\n6 - Калькулятор многочленов; \n0 - Для выхода из программы;\n";

		while (!(cin >> o))
		{
			cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (o)
		{
		case 0:
		{
			cout << "Выполнение программы завершено" << endl;
			break;
		}
		case 1:
		{
			cout << "Вы выбрали работу с матрицами\n";
			work_matrix();
			break;
		}
		case 2:
		{
			cout << "Вы выбрали работу с дробями\n";
			work_fraction();
			break;
		}
		case 3:
		{
			cout << "Вы выбрали работу с формулами комбинаторики\n";
			work_combinatorics_formulas();
			break;
		}
		case 4:
		{
			cout << "Вы выбрали работу с теорией вероятности и математической статистикой\n";
			work_probability_and_math_statistic();
			break;
		}
		case 5:
		{
			cout << "Вы выбрали работу с функциями\n";
			work_function();
			break;
		}
		case 6:
		{
			cout << "Вы выбрали работу с многочленами\n";
			work_polinom();
			break;
		}
		default:	
			cout << "Неверный выбор действия" << endl;
		}

	} while (o != 0);

	return 0;
}