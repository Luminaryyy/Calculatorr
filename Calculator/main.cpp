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
		cout << "�������� ��������, ����������� ��� ��������, ���:\n1 - ����� ����� F(x) = 0 �� �������\n2 - ����� ����������� �� �������\n0 - ����� �� ���������" << endl;
		while (!(cin >> o))
		{
			cout << "������������ ����. ����������, ������� ����� �����: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		switch (o)
		{
		case 0:
			cout << "���������� ��������� ���������" << endl;
			break;
		case 1:
			cout << "�� ������� ����� ����� F(x) = 0 �� �������" << endl;
			searchRoot();
			break;
		case 2:
			cout << "�� ������� ����� ����������� �� �������" << endl;
			searchExtremums();
			break;
		default:
			cout << "�������� ����� ��������" << endl;
		}
	} while (o != 0);

	return 0;
}