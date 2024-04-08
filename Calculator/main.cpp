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
		cout << "�������� ��� ������������, � ������� ������ ��������:\n1 - ��������� �����������;"
			<< "\n2 - ����������� ������������ ������; \n3 - ����������� ������ �������������;"
			<< "\n4 - ����������� ������ ����������� � �������������� ����������; \n5 - ����������� �������;"
			<< "\n6 - ����������� �����������; \n0 - ��� ������ �� ���������;\n";

		while (!(cin >> o))
		{
			cout << "������������ ����. ����������, ������� ����� �����: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (o)
		{
		case 0:
		{
			cout << "���������� ��������� ���������" << endl;
			break;
		}
		case 1:
		{
			cout << "�� ������� ������ � ���������\n";
			work_matrix();
			break;
		}
		case 2:
		{
			cout << "�� ������� ������ � �������\n";
			work_fraction();
			break;
		}
		case 3:
		{
			cout << "�� ������� ������ � ��������� �������������\n";
			work_combinatorics_formulas();
			break;
		}
		case 4:
		{
			cout << "�� ������� ������ � ������� ����������� � �������������� �����������\n";
			work_probability_and_math_statistic();
			break;
		}
		case 5:
		{
			cout << "�� ������� ������ � ���������\n";
			work_function();
			break;
		}
		case 6:
		{
			cout << "�� ������� ������ � ������������\n";
			work_polinom();
			break;
		}
		default:	
			cout << "�������� ����� ��������" << endl;
		}

	} while (o != 0);

	return 0;
}