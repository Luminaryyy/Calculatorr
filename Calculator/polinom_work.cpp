#include "polinom.h"
using namespace std;


void print_poly(int* p) {
	bool f = true;
	for (int i = MAX_DEG; i >= 0; i--)
	{
		if (p[i] != 0) {
			if (p[i] < 0) {
				cout << " - " << -p[i] << "*x^" << i;
				f = false;
			}
			else {
				if (f) {
					cout << p[i] << "*x^" << i;
					f = false;
				}
				else {
					cout << " + " << p[i] << "*x^" << i;
				}
			}
		}
	}
	if (f == true) cout << "0";
	cout << "\n";
}

void get_poly(int* p1) {
	int iD = 1, iC = 1;
	while (iD != 0 || iC != 0)
	{
		do {
			cin >> iD >> iC;
			if (!(iD <= MAX_DEG && iD >= 0)) {
				cout << "<!> Поддерживаются только степени до " << MAX_DEG << "\n";
			}
		} while (!(iD <= MAX_DEG && iD >= 0));
		p1[iD] += iC;
	}
}
void poly_clear(int* p) {
	for (int i = 0; i <= MAX_DEG; i++)
	{
		p[i] = 0;
	}
}
void poly_addition(int* p1, int* p2, int* pr) {
	for (int i = 0; i <= MAX_DEG; i++)
	{
		pr[i] = p1[i] + p2[i];
	}
}

void poly_subtraction(int* p1, int* p2, int* pr) {
	for (int i = 0; i <= MAX_DEG; i++)
	{
		pr[i] = p1[i] - p2[i];
	}
}

void poly_multiplication(int* p1, int* p2, int* pr) {
	int mdp = 0, dm1 = 0, dm2 = 0;
	bool dm1found = false, dm2found = false;
	for (int i = MAX_DEG; i > 0; i--) {
		if (!dm1found && p1[i] != 0) {
			dm1 = i;
			dm1found = true;
		}
		if (!dm2found && p2[i] != 0) {
			dm2 = i;
			dm2found = true;
		}
		if (dm1found && dm2found) break;
	}
	mdp = dm1 + dm2;

	for (int i = 0; i <= mdp; i++) {
		for (int j = 0; j <= i; j++) {
			pr[i] += (p1[j] * p2[i - j]);
		}
	}
}

void poly_mulbynum(int* p1, int p2, int* pr) {
	for (int i = -MAX_DEG; i <= MAX_DEG; i++) {
		pr[i] = p1[i] * p2;
	}
}

void poly_deriv(int* p, int* pr) {
	for (int i = 0; i <= MAX_DEG; i++) {
		pr[i] = p[i + 1] * (i + 1);
	}
}

void poly_div(int* p1, int* p2, int* pr, int* po) {
	int* pqq = new int[MAX_DEG * 2] {};
	int dm1 = 0, dm2 = 0;
	bool dm1found = false, dm2found = false;
	for (int i = MAX_DEG; i > 0; i--) {
		if (!dm1found && p1[i] != 0) {
			dm1 = i;
			dm1found = true;
		}
		if (!dm2found && p2[i] != 0) {
			dm2 = i;
			dm2found = true;
		}
		if (dm1found && dm2found) break;
	}
	if (dm2 <= dm1) {
		for (int i = 0; i <= (dm1 - dm2); i++)
		{
			pr[dm1 - dm2 - i] = p1[dm1 - i] / p2[dm2];
			poly_addition(po, pr, po);

			poly_multiplication(pr, p2, pqq);
			poly_clear(pr);

			poly_subtraction(p1, pqq, p1);
			poly_clear(pqq);
		}
		cout << "ЧАСТНОЕ:\n";
		print_poly(po);
		//print_poly(pqq);
		cout << "ОСТАТОК:\n";
		print_poly(p1);
	}
	else {
		for (int i = 0; i <= (dm2 - dm1); i++)
		{
			pr[dm2 - dm1 - i] = p2[dm2 - i] / p1[dm1];
			poly_addition(po, pr, po);

			poly_multiplication(pr, p1, pqq);
			poly_clear(pr);

			poly_subtraction(p2, pqq, p2);
			poly_clear(pqq);
		}
		cout << "ЧАСТНОЕ:\n";
		print_poly(po);
		//print_poly(pqq);
		cout << "ОСТАТОК:\n";
		print_poly(p2);
	}
}


void work_polinom()
{
	int* p1 = new int[MAX_DEG * 2] {};
	int* p2 = new int[MAX_DEG * 2] {};
	int* pr = new int[MAX_DEG * 2] {};
	int* po = new int[MAX_DEG * 2] {};
	int nm = 0;

	bool stop = false;
	int o;
	do {
		cout << "0. Выход\n";
		cout << "1. Сложение многочленов\n";
		cout << "2. Вычитание многочленов\n";
		cout << "3. Умножение многочленов\n";
		cout << "4. Умножение многочлена на число\n";
		cout << "5. Вычисление производной от многочлена\n";
		cout << "6. Деление многочленов в столбик\n";
		cout << "Выберите операцию: ";
		cin >> o;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (o) {
		case 0:
			stop = true;
			break;
		case 1:
			cout << "\t\t/------------------------/\n"
				 << "\t\t|                        |\n"
				 << "\t\t/  Сложение многочленов  /\n"
				 << "\t\t|                        |\n"
				 << "\t\t/------------------------/\n";

			cout << "ВВОД ПЕРВОГО ПОЛИНОМА\n";
			cout << "Для каждого члена введите сначала степень X,\n";
			cout << "а затем через пробел коэффициент X\n";
			cout << "закончить ввод полинома можно парой 0 0\n";
			get_poly(p1);
			cout << "ВВОД ВТОРОГО ПОЛИНОМА\n";
			get_poly(p2);
			poly_addition(p1, p2, p1);
			cout << "РЕЗУЛЬТАТ:\n";
			print_poly(p1);
			break;
		case 2:
			cout << "\t\t/-------------------------/\n"
				 << "\t\t|                         |\n"
				 << "\t\t/  Вычитание многочленов  /\n"
				 << "\t\t|                         |\n"
				 << "\t\t/-------------------------/\n";

			cout << "ВВОД ПЕРВОГО ПОЛИНОМА\n";
			cout << "Для каждого члена введите сначала степень X,\n";
			cout << "а затем через пробел коэффициент X\n";
			cout << "закончить ввод полинома можно парой 0 0\n";
			get_poly(p1);
			cout << "ВВОД ВТОРОГО ПОЛИНОМА\n";
			get_poly(p2);
			poly_subtraction(p1, p2, p1);
			cout << "РЕЗУЛЬТАТ:\n";
			print_poly(p1);
			break;
		case 3:
			cout << "\t\t/-------------------------/\n"
				 << "\t\t|                         |\n"
				 << "\t\t/  Умножение многочленов  /\n"
				 << "\t\t|                         |\n"
				 << "\t\t/-------------------------/\n";

			cout << "ВВОД ПЕРВОГО ПОЛИНОМА\n";
			cout << "Для каждого члена введите сначала степень X,\n";
			cout << "а затем через пробел коэффициент X\n";
			cout << "закончить ввод полинома можно парой 0 0\n";
			get_poly(p1);
			cout << "ВВОД ВТОРОГО ПОЛИНОМА\n";
			get_poly(p2);
			poly_multiplication(p1, p2, p1);
			cout << "РЕЗУЛЬТАТ:\n";
			print_poly(p1);
			break;
		case 4:
			cout << "\t\t/---------------------------------/\n"
				 << "\t\t|                                 |\n"
				 << "\t\t/  Умножение многочлена на число  /\n"
				 << "\t\t|                                 |\n"
				 << "\t\t/---------------------------------/\n";

			cout << "ВВОД ПОЛИНОМА\n";
			cout << "Для каждого члена введите сначала степень X,\n";
			cout << "а затем через пробел коэффициент X\n";
			cout << "закончить ввод полинома можно парой 0 0\n";
			get_poly(p1);

			cout << "ВВОД ЧИСЛА\n";
			cin >> nm;
			poly_mulbynum(p1, nm, p1);
			cout << "РЕЗУЛЬТАТ:\n";
			print_poly(p1);
			break;
		case 5:
			cout << "\t\t/---------------------------------/\n"
				 << "\t\t|                                 |\n"
				 << "\t\t/  Деление многочленов в столбик  /\n"
				 << "\t\t|                                 |\n"
				 << "\t\t/---------------------------------/\n";

			cout << "ВВОД ПОЛИНОМА\n";
			cout << "Для каждого члена введите сначала степень X,\n";
			cout << "а затем через пробел коэффициент X\n";
			cout << "закончить ввод полинома можно парой 0 0\n";
			get_poly(p1);
			poly_deriv(p1, pr);
			cout << "РЕЗУЛЬТАТ:\n";
			print_poly(pr);
			break;
		case 6:
			cout << "\t\t/----------------------------------------/\n"
				<< "\t\t|                                        |\n"
				<< "\t\t/  Вычисление производной от многочлена  /\n"
				<< "\t\t|                                        |\n"
				<< "\t\t/----------------------------------------/\n";

			cout << "ВВОД ПЕРВОГО ПОЛИНОМА\n";
			cout << "Для каждого члена введите сначала степень X,\n";
			cout << "а затем через пробел коэффициент X\n";
			cout << "закончить ввод полинома можно парой 0 0\n";
			get_poly(p1);
			cout << "ВВОД ВТОРОГО ПОЛИНОМА\n";
			get_poly(p2);
			poly_div(p1, p2, pr, po);
			break;
		default:
			cout << "<!> Введите целое число от 0 до 6 - номер необходимой операции!\n";
			break;
		}
		poly_clear(p1);
		poly_clear(p2);
		poly_clear(po);
		poly_clear(pr);

	} while (!stop);
}