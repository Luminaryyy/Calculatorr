#include "matrix.h"
using namespace std;

double Determinant(double** matrix, int n) {

    if (n == 1) return matrix[0][0];

    double det = 0;

    double** submatrix = new double* [n - 1];
    for (int i = 0; i < n - 1; i++)
        submatrix[i] = new double[n - 1];

    for (int i = 0; i < n; i++) {
        int sub_i = 0;
        for (int row = 1; row < n; row++) {
            int sub_j = 0;
            for (int column = 0; column < n; column++)
                if (column != i) submatrix[sub_i][sub_j++] = matrix[row][column];
            sub_i++;
        }

        int k = -1;
        if (i % 2 == 0) k = 1;
        det += k * matrix[0][i] * Determinant(submatrix, n - 1);
    }

    for (int i = 0; i < n - 1; i++)
        delete[]submatrix[i];
    delete[]submatrix;

    return det;
}


double DetOfMinor(double** matrix, int row, int column, int n) {

    double** minor = new double* [n - 1];
    for (int i = 0; i < n - 1; ++i)
        minor[i] = new double[n - 1];

    int minor_row = 0, minor_column = 0;

    for (int i = 0; i < n; ++i) {
        if (i == row) continue;

        minor_column = 0;
        for (int j = 0; j < n; ++j) {
            if (j == column) continue;
            minor[minor_row][minor_column++] = matrix[i][j];
        }
        minor_row++;
    }

    double minorDet = Determinant(minor, n - 1);

    for (int i = 0; i < n - 1; ++i) {
        delete[] minor[i];
    }
    delete[] minor;

    return minorDet;
}



void matrix_func1()
{
	int n, m;
	int limit = 8;

	cout << "Введите количество строк и столбцов матриц: ";
	do
	{
		cin >> n >> m;
		if (!((n > 0) && (m > 0)))
			cout << "Количество строк и столбцов должно быть больше нуля, попробуйте ещё раз: ";
	} while (!((n > 0) && (m > 0)));

	double** a = new double* [n];
	double** b = new double* [n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new double[m];
		b[i] = new double[m];
	}

	cout << "Органичение длины числа - 8\n";

	cout << "Заполните матрицу А: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << "Введите элемент a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}

	cout << "Заполните матрицу B: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << "Введите элемент b[" << i << "][" << j << "]: ";
			cin >> b[i][j];
		}

	cout << "\nМатрица A:\n";
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--\n";
	for (int i = 0; i < n; i++)
	{
		cout << "|";
		for (int j = 0; j < m; j++)
		{
			string x = regex_replace(to_string(a[i][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			x = regex_replace(x, regex("\\,?$"), "");
			cout << left << setw(limit) << x << " ";
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--";

	cout << "\nМатрица B:\n";
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--\n";
	for (int i = 0; i < n; i++)
	{
		cout << "|";
		for (int j = 0; j < m; j++)
		{
			string x = regex_replace(to_string(b[i][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			x = regex_replace(x, regex("\\,?$"), "");
			cout << left << setw(limit) << x << " ";
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--";

	cout << "\nМатрица C = A + B:\n";
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--\n";
	for (int i = 0; i < n; i++)
	{
		cout << "|";
		for (int j = 0; j < m; j++)
		{
			string a_str = regex_replace(to_string(a[i][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			string b_str = regex_replace(to_string(b[i][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			string c = regex_replace(to_string(stod(a_str) + stod(b_str)).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			c = regex_replace(c, regex("\\,?$"), "");
			cout << left << setw(limit) << c << " ";
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--";

	for (int i = 0; i < n; i++)
	{
		delete[]a[i];
		delete[]b[i];
	}

	delete[]a;
	delete[]b;

	cout << "\n-----------------------------------------------------------\n\n";
}


void matrix_func2()
{
	int n, m;
	int limit = 8;

	cout << "Введите количество строк и столбцов матриц: ";
	do
	{
		cin >> n >> m;
		if (!((n > 0) && (m > 0)))
			cout << "Количество строк и столбцов должно быть больше нуля, попробуйте ещё раз: ";
	} while (!((n > 0) && (m > 0)));

	double** a = new double* [n];
	double** b = new double* [n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new double[m];
		b[i] = new double[m];
	}

	cout << "Органичение длины числа - 8\n";

	cout << "Заполните матрицу А: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << "Введите элемент a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}

	cout << "Заполните матрицу B: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << "Введите элемент b[" << i << "][" << j << "]: ";
			cin >> b[i][j];
		}

	cout << "\nМатрица A:\n";
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--\n";
	for (int i = 0; i < n; i++)
	{
		cout << "|";
		for (int j = 0; j < m; j++)
		{
			string x = regex_replace(to_string(a[i][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			x = regex_replace(x, regex("\\,?$"), "");
			cout << left << setw(limit) << x << " ";
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--";

	cout << "\nМатрица B:\n";
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--\n";
	for (int i = 0; i < n; i++)
	{
		cout << "|";
		for (int j = 0; j < m; j++)
		{
			string x = regex_replace(to_string(b[i][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			x = regex_replace(x, regex("\\,?$"), "");
			cout << left << setw(limit) << x << " ";
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--";

	cout << "\nМатрица C = A - B:\n";
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--\n";
	for (int i = 0; i < n; i++)
	{
		cout << "|";
		for (int j = 0; j < m; j++)
		{
			string a_str = regex_replace(to_string(a[i][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			string b_str = regex_replace(to_string(b[i][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			string c = regex_replace(to_string(stod(a_str) - stod(b_str)).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			c = regex_replace(c, regex("\\,?$"), "");
			cout << left << setw(limit) << c << " ";
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--";

	for (int i = 0; i < n; i++)
	{
		delete[]a[i];
		delete[]b[i];
	}

	delete[]a;
	delete[]b;

	cout << "\n-----------------------------------------------------------\n\n";
}


void matrix_func3()
{
	int n1, m1, n2, m2;
	int limit = 8;

	cout << "Введите количество строк и стобцов матрицы А: ";
	do
	{
		cin >> n1 >> m1;
		if (!((n1 > 0) && (m1 > 0)))
			cout << "Количество строк и столбцов должно быть больше нуля, попробуйте ещё раз: ";
	} while (!((n1 > 0) && (m1 > 0)));

	n2 = m1;

	cout << "Введите количество столбцов матрицы B: ";
	do
	{
		cin >> m2;
		if (m2 <= 0)
			cout << "Количество столбцов должно быть больше нуля, попробуйте ещё раз: ";
	} while (m2 <= 0);

	double** a = new double* [n1];
	double** b = new double* [n2];

	for (int i = 0; i < n1; i++)
		a[i] = new double[m1];

	for (int i = 0; i < n2; i++)
		b[i] = new double[m2];

	cout << "Органичение длины числа - 8\n";

	cout << "Заполните матрицу А: " << endl;
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < m1; j++)
		{
			cout << "Введите элемент a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}

	cout << "Заполните матрицу B: " << endl;
	for (int i = 0; i < n2; i++)
		for (int j = 0; j < m2; j++)
		{
			cout << "Введите элемент b[" << i << "][" << j << "]: ";
			cin >> b[i][j];
		}

	cout << "\nМатрица A:\n";
	for (int i = 0; i < m1; i++)
		cout << "---------";
	cout << "--\n";
	for (int i = 0; i < n1; i++)
	{
		cout << "|";
		for (int j = 0; j < m1; j++)
		{
			string x = regex_replace(to_string(a[i][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			x = regex_replace(x, regex("\\,?$"), "");
			cout << left << setw(limit) << x << " ";
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < m1; i++)
		cout << "---------";
	cout << "--";

	cout << "\nМатрица B:\n";
	for (int i = 0; i < m2; i++)
		cout << "---------";
	cout << "--\n";
	for (int i = 0; i < n2; i++)
	{
		cout << "|";
		for (int j = 0; j < m2; j++)
		{
			string x = regex_replace(to_string(b[i][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			x = regex_replace(x, regex("\\,?$"), "");
			cout << left << setw(limit) << x << " ";
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < m2; i++)
		cout << "---------";
	cout << "--";

	cout << "\nМатрица C = A * B:\n";
	for (int i = 0; i < m2; i++)
		cout << "---------";
	cout << "--\n";
	for (int i = 0; i < n1; i++)
	{
		cout << "|";
		for (int j = 0; j < m2; j++)
		{
			double s = 0;
			for (int t = 0; t < m1; t++)
				s += stod(regex_replace(to_string(a[i][t]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2")) *
				stod(regex_replace(to_string(b[t][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2"));
			string x = regex_replace(to_string(s).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			x = regex_replace(x, regex("\\,?$"), "");
			cout << left << setw(limit) << x << " ";
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < m2; i++)
		cout << "---------";
	cout << "--";

	for (int i = 0; i < n1; i++)
		delete[]a[i];

	for (int i = 0; i < n2; i++)
		delete[]b[i];

	delete[]a;
	delete[]b;

	cout << "\n-----------------------------------------------------------\n\n";
}


void matrix_func4()
{
	int n, m;
	int limit = 8;
	double k;

	cout << "Введите количество строк и столбцов матрицы: ";
	do
	{
		cin >> n >> m;
		if (!((n > 0) && (m > 0)))
			cout << "Количество строк и столбцов должно быть больше нуля, попробуйте ещё раз: ";
	} while (!((n > 0) && (m > 0)));

	double** a = new double* [n];

	for (int i = 0; i < n; i++)
		a[i] = new double[m];

	cout << "Органичение длины числа - 8\n";

	cout << "Заполните матрицу А: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << "Введите элемент a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}

	cout << "Ведите число k: ";
	cin >> k;
	string k_str = regex_replace(to_string(k).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");

	cout << "\nМатрица A:\n";
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--\n";
	for (int i = 0; i < n; i++)
	{
		cout << "|";
		for (int j = 0; j < m; j++)
		{
			string x = regex_replace(to_string(a[i][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			x = regex_replace(x, regex("\\,?$"), "");
			cout << left << setw(limit) << x << " ";
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--";

	cout << "\nМатрица C = k * A:\n";
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--\n";
	for (int i = 0; i < n; i++)
	{
		cout << "|";
		for (int j = 0; j < m; j++)
		{
			string a_str = regex_replace(to_string(a[i][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			string c = regex_replace(to_string(stod(k_str) * stod(a_str)).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			c = regex_replace(c, regex("\\,?$"), "");
			cout << left << setw(limit) << c << " ";
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--";

	for (int i = 0; i < n; i++)
		delete[]a[i];

	delete[]a;

	cout << "\n-----------------------------------------------------------\n\n";
}


void matrix_func5()
{
	int n, m;
	int limit = 8;
	double k;

	cout << "Введите количество строк и столбцов матрицы: ";
	do
	{
		cin >> n >> m;
		if (!((n > 0) && (m > 0)))
			cout << "Количество строк и столбцов должно быть больше нуля, попробуйте ещё раз: ";
	} while (!((n > 0) && (m > 0)));

	double** a = new double* [n];

	for (int i = 0; i < n; i++)
		a[i] = new double[m];

	cout << "Органичение длины числа - 8\n";

	cout << "Заполните матрицу А: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << "Введите элемент a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}

	cout << "Ведите число k: ";
	cin >> k;
	string k_str = regex_replace(to_string(k).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");

	cout << "\nМатрица A:\n";
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--\n";
	for (int i = 0; i < n; i++)
	{
		cout << "|";
		for (int j = 0; j < m; j++)
		{
			string x = regex_replace(to_string(a[i][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			x = regex_replace(x, regex("\\,?$"), "");
			cout << left << setw(limit) << x << " ";
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--";

	cout << "\nМатрица C = A + k:\n";
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--\n";
	for (int i = 0; i < n; i++)
	{
		cout << "|";
		for (int j = 0; j < m; j++)
		{
			string a_str = regex_replace(to_string(a[i][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			string c = regex_replace(to_string(stod(a_str) + stod(k_str)).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			c = regex_replace(c, regex("\\,?$"), "");
			cout << left << setw(limit) << c << " ";
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--";

	for (int i = 0; i < n; i++)
		delete[]a[i];

	delete[]a;

	cout << "\n-----------------------------------------------------------\n\n";
}


void matrix_func6()
{
	int n, m;
	int limit = 8;

	cout << "Введите количество строк и столбцов матрицы: ";
	do
	{
		cin >> n >> m;
		if (!((n > 0) && (m > 0)))
			cout << "Количество строк и столбцов должно быть больше нуля, попробуйте ещё раз: ";
	} while (!((n > 0) && (m > 0)));

	double** a = new double* [n];
	double** a1 = new double* [m];

	for (int i = 0; i < n; i++)
		a[i] = new double[m];

	for (int i = 0; i < m; i++)
		a1[i] = new double[n];

	cout << "Органичение длины числа - 8\n";

	cout << "Заполните матрицу А: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << "Введите элемент a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
			a1[j][i] = a[i][j];
		}

	cout << "\nМатрица A:\n";
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--\n";
	for (int i = 0; i < n; i++)
	{
		cout << "|";
		for (int j = 0; j < m; j++)
		{
			string x = regex_replace(to_string(a[i][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			x = regex_replace(x, regex("\\,?$"), "");
			cout << left << setw(limit) << x << " ";
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < m; i++)
		cout << "---------";
	cout << "--";

	cout << "\nМатрица A^t:\n";
	for (int i = 0; i < n; i++)
		cout << "---------";
	cout << "--\n";
	for (int i = 0; i < m; i++)
	{
		cout << "|";
		for (int j = 0; j < n; j++)
		{
			string x = regex_replace(to_string(a1[i][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			x = regex_replace(x, regex("\\,?$"), "");
			cout << left << setw(limit) << x << " ";
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < n; i++)
		cout << "---------";
	cout << "--";

	for (int i = 0; i < n; i++)
		delete[]a[i];

	for (int i = 0; i < m; i++)
		delete[]a1[i];

	delete[]a;
	delete[]a1;

	cout << "\n-----------------------------------------------------------\n\n";
}


void matrix_func7()
{
	int n;
	int limit = 8;
	double det;

	cout << "Введите порядок квадратной матрицы: ";
	do
	{
		cin >> n;
		if (n <= 0)
			cout << "Количество строк и столбцов должно быть больше нуля, попробуйте ещё раз: ";
	} while (n <= 0);

	double** a = new double* [n];

	for (int i = 0; i < n; i++)
		a[i] = new double[n];

	cout << "Органичение длины числа - 8\n";

	cout << "Заполните матрицу А: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "Введите элемент a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}

	cout << "\nМатрица A:\n";
	for (int i = 0; i < n; i++)
		cout << "---------";
	cout << "--\n";
	for (int i = 0; i < n; i++)
	{
		cout << "|";
		for (int j = 0; j < n; j++)
		{
			string x = regex_replace(to_string(a[i][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			x = regex_replace(x, regex("\\,?$"), "");
			cout << left << setw(limit) << x << " ";
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < n; i++)
		cout << "---------";
	cout << "--";

	det = Determinant(a, n);
	if (det == 0)
		cout << "\nОпределитель равен 0, обратной матрицы не существует";
	else
	{
		double** inverse = new double* [n];
		for (int i = 0; i < n; i++)
			inverse[i] = new double[n];

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int minorDet = DetOfMinor(a, i, j, n);
				int k = -1;
				if ((i + j) % 2 == 0) k = 1;
				inverse[j][i] = k * minorDet / det;
			}
		}

		string x = regex_replace(to_string(det).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
		x = regex_replace(x, regex("\\,?$"), "");
		cout << "\nМатрциа A^-1: " << endl;
		for (int i = 0; i < n; i++)
			cout << "---------";
		cout << "--\n";
		for (int i = 0; i < n; i++)
		{
			cout << "|";
			for (int j = 0; j < n; j++)
			{
				string x = regex_replace(to_string(inverse[i][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
				x = regex_replace(x, regex("\\,?$"), "");
				cout << left << setw(limit) << x << " ";
			}
			cout << "|" << endl;
		}
		for (int i = 0; i < n; i++)
			cout << "---------";
		cout << "--";
	}

	for (int i = 0; i < n; i++)
		delete[]a[i];

	delete[]a;

	cout << "\n-----------------------------------------------------------\n\n";
}


void matrix_func8()
{
	int n;
	int limit = 8;
	double det;

	cout << "Введите порядок квадратной матрицы: ";
	do
	{
		cin >> n;
		if (n <= 0)
			cout << "Количество строк и столбцов должно быть больше нуля, попробуйте ещё раз: ";
	} while (n <= 0);

	double** a = new double* [n];

	for (int i = 0; i < n; i++)
		a[i] = new double[n];

	cout << "Органичение длины числа - 8\n";

	cout << "Заполните матрицу А: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "Введите элемент a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}

	cout << "\nМатрица A:\n";
	for (int i = 0; i < n; i++)
		cout << "---------";
	cout << "--\n";
	for (int i = 0; i < n; i++)
	{
		cout << "|";
		for (int j = 0; j < n; j++)
		{
			string x = regex_replace(to_string(a[i][j]).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
			x = regex_replace(x, regex("\\,?$"), "");
			cout << left << setw(limit) << x << " ";
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < n; i++)
		cout << "---------";
	cout << "--";

	det = Determinant(a, n);
	string x = regex_replace(to_string(det).substr(0, 8), regex("(\\,\\d*?)0+$|^([1-9]+)0+$"), "\$1\$2");
	x = regex_replace(x, regex("\\,?$"), "");
	cout << "\n|A| = " << x;

	for (int i = 0; i < n; i++)
		delete[]a[i];

	delete[]a;

	cout << "\n-----------------------------------------------------------\n\n";
}


void work_matrix()
{
	string str;
	int n;

	do
	{
		cout << "1 - Сложение матриц\n";
		cout << "2 - Вычитание матриц\n";
		cout << "3 - Умножение матриц\n";
		cout << "4 - Умножение матрицы на число\n";
		cout << "5 - Сложение матрциы с числом (вычитание)\n";
		cout << "6 - Транспонирование матрицы\n";
		cout << "7 - Обратная матрица\n";
		cout << "8 - Определитель\n";
		cout << "0 - Выход в меню\n\n";
		cout << "Для выбора действия введите сосответствующее число: ";

		do
		{
			cin >> str;
			if (!((str.length() == 1) && ((str == "1") || (str == "2") || (str == "3") || (str == "4") ||
				(str == "5") || (str == "6") || (str == "7") || (str == "8") || (str[0] == '0'))))
				cout << "Ошибка ввода, попробуйте ещё раз: ";
		} while (!((str.length() == 1) && ((str == "1") || (str == "2") || (str == "3") || (str == "4") ||
			(str == "5") || (str == "6") || (str == "7") || (str == "8") || (str[0] == '0'))));

		n = stoi(str);

		switch (n)
		{
		case 1:
			cout << "\t\t/-------------------/\n"
				<< "\t\t|                   |\n"
				<< "\t\t/  Сложение матриц  /\n"
				<< "\t\t|                   |\n"
				<< "\t\t/-------------------/\n";
			matrix_func1();
			break;
		case 2:
			cout << "\t\t/--------------------/\n"
				<< "\t\t|                    |\n"
				<< "\t\t/  Вычитание матриц  /\n"
				<< "\t\t|                    |\n"
				<< "\t\t/--------------------/\n";
			matrix_func2();
			break;
		case 3:
			cout << "\t\t/--------------------/\n"
				<< "\t\t|                    |\n"
				<< "\t\t/  Умножение матриц  /\n"
				<< "\t\t|                    |\n"
				<< "\t\t/--------------------/\n";
			matrix_func3();
			break;
		case 4:
			cout << "\t\t/------------------------------/\n"
				<< "\t\t|                              |\n"
				<< "\t\t/  Умножение матрицы на число  /\n"
				<< "\t\t|                              |\n"
				<< "\t\t/------------------------------/\n";
			matrix_func4();
			break;
		case 5:
			cout << "\t\t/-----------------------------------------/\n"
				<< "\t\t|                                         |\n"
				<< "\t\t/  Сложение (вычитание) матрицы с числом  /\n"
				<< "\t\t|                                         |\n"
				<< "\t\t/-----------------------------------------/\n";
			matrix_func5();
			break;
		case 6:
			cout << "\t\t/----------------------------/\n"
				<< "\t\t|                            |\n"
				<< "\t\t/  Транспонирование матрицы  /\n"
				<< "\t\t|                            |\n"
				<< "\t\t/----------------------------/\n";
			matrix_func6();
			break;
		case 7:
			cout << "\t\t/--------------------/\n"
				<< "\t\t|                    |\n"
				<< "\t\t/  Обратная матрица  /\n"
				<< "\t\t|                    |\n"
				<< "\t\t/--------------------/\n";
			matrix_func7();
			break;
		case 8:
			cout << "\t\t/------------------------/\n"
				<< "\t\t|                        |\n"
				<< "\t\t/  Определитель матрицы  /\n"
				<< "\t\t|                        |\n"
				<< "\t\t/------------------------/\n";
			matrix_func8();
			break;
		case 0:
			cout << "Вы вышли в меню\n";
		}

	} while (n != 0);
}