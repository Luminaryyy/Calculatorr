#include "probability_and_math_statistic.h"
using namespace std;

void Probability() {
	double m, n;
	do {
		cout << "Введите число благоприятных исходов M: ";
		cin >> m;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (m < 0) cout << "<!> M не может быть отрицательным!\n";
	} while (m < 0);
	do {
		cout << "Введите число всех исходов N: ";
		cin >> n;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (n <= 0 || n < m) cout << "<!> N > 0 и N >= M!\n";
	} while (n <= 0 || n < m);

	cout << "M/N = " << m / n << "\n\n";
}

void Variance() {
	int n;
	do {
		cout << "Выберите кол-во величин N: ";
		cin >> n;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (n < 2) cout << "<!> N > 1!\n";
	} while (n < 2);

	double* x{ new double[n] {} };
	double* p{ new double[n] {} };

	double Mx = 0, Mx2 = 0, Dx, TotalP = 0;

	cout << "Введите значения величин и их вероятности\n";
	bool isGoodP, isTotal1 = false;

	while (!isTotal1) {
		for (int i = 0; i < n; ++i) {

			cout << "x(" << i + 1 << ") = ";
			cin >> x[i];
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			isGoodP = false;
			do {
				cout << "p(" << i + 1 << ") = ";
				cin >> p[i];
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (p[i] < 0) cout << "<!> Вероятность не может быть отрицательной!\n";
				else if (p[i] > 1) cout << "<!> Вероятность не может быть больше 1!\n";
				else isGoodP = true;
			} while (!isGoodP);
			TotalP += p[i];
			if (TotalP > 1) break;
		}
		if (TotalP == 1) isTotal1 = true;
		else {
			cout << "<!> Суммарная вероятность должна быть равна 1!\n";
			cout << "<!> Текущая вероятность: " << TotalP << "\n";
			cout << "<!> Попробуйте ещё раз\n";
			TotalP = 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		Mx = Mx + (x[i] * p[i]);
		Mx2 = Mx2 + (x[i] * x[i] * p[i]);
	}
	Dx = Mx2 - (Mx * Mx);
	cout << "D: " << Dx << "\n\n";
	delete[]x;
	delete[]p;
}

void ExpectedValue() {
	int n;
	do {
		cout << "Выберите кол-во величин N: ";
		cin >> n;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (n <= 0) cout << "<!> N > 0!\n";
	} while (n <= 0);

	double* x{ new double[n] {} };
	double* p{ new double[n] {} };

	double Mx = 0, TotalP = 0;

	cout << "Введите значения величин и их вероятности\n";
	bool isGoodP, isTotal1 = false;

	while (!isTotal1) {
		for (int i = 0; i < n; ++i) {

			cout << "x(" << i + 1 << ") = ";
			cin >> x[i];
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			isGoodP = false;
			do {
				cout << "p(" << i + 1 << ") = ";
				cin >> p[i];
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (p[i] < 0) cout << "<!> Вероятность не может быть отрицательной!\n";
				else if (p[i] > 1) cout << "<!> Вероятность не может быть больше 1!\n";
				else isGoodP = true;
			} while (!isGoodP);
			TotalP += p[i];
			if (TotalP > 1) break;
		}
		if (TotalP == 1) isTotal1 = true;
		else {
			cout << "<!> Суммарная вероятность должна быть равна 1!\n";
			cout << "<!> Текущая вероятность: " << TotalP << "\n";
			cout << "<!> Попробуйте ещё раз\n";
			TotalP = 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		Mx = Mx + (x[i] * p[i]);
	}
	cout << "M: " << Mx << "\n\n";
	delete[]x;
	delete[]p;
}

void work_probability_and_math_statistic()
{
	bool stop = false;
	int o;
	do {
		cout << "0. Выход\n";
		cout << "1. Вероятность m/n\n";
		cout << "2. Дисперсия для дискретного распределения величин\n";
		cout << "3. Мат. ожидание для дискретного распределения величин\n";
		cout << "Выберите операцию: ";
		cin >> o;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (o) {
		case 0:
			stop = true;
			break;
		case 1:
			cout << "\t\t/-------------------/\n"
				 << "\t\t|                   |\n"
				 << "\t\t/  Вероятность m/n  /\n"
				 << "\t\t|                   |\n"
				 << "\t\t/-------------------/\n";
			Probability();
			break;
		case 2:
			cout << "\t\t/---------------------------------------------------/\n"
				 << "\t\t|                                                   |\n"
				 << "\t\t/  Дисперсия для дискретного распределения велечин  /\n"
				 << "\t\t|                                                   |\n"
				 << "\t\t/---------------------------------------------------/\n";
			Variance();
			break;
		case 3:
			cout << "\t\t/-------------------------------------------------------/\n"
				 << "\t\t|                                                       |\n"
				 << "\t\t/  Мат. ожидание для дискретного распределения величин  /\n"
				 << "\t\t|                                                       |\n"
				 << "\t\t/-------------------------------------------------------/\n";
			ExpectedValue();
			break;
		default:
			cout << "<!> Введите целое число от 0 до 3 - номер необходимой операции!\n";
			break;
		}
	} while (!stop);
}