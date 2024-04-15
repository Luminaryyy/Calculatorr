#include <iostream>
#include <iomanip>
#include <limits>
#include <locale.h>
#include <cmath>
#include "combinatorics_formulas.h"
using namespace std;


int factorial(int x)
{
    int fact = 1;
    while (x)
    {
        fact *= x;
        x--;
    }
    return fact;
}

void work_combinatorics_formulas()
{
    bool fl3 = false, fl1 = false;
    int fl2;
    int n, k;
    do
    {
        cout << "Выберите операцию" << endl;
        cout << "1.Число размещений с повторением" << endl;
        cout << "2.Число размещений без повторений" << endl;
        cout << "3.Число сочетаний c повторением" << endl;
        cout << "4.Число сочетаний без повторения" << endl;
        cout << "5.Число перестановок" << endl;
        cin >> fl2;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (fl2)
        {
        case 1:
        {
            cout << "\t\t/----------------------------------/\n"
                 << "\t\t|                                  |\n"
                 << "\t\t/  Число размещений с повторением  /\n"
                 << "\t\t|                                  |\n"
                 << "\t\t/----------------------------------/\n";

            do
            {
                cout << "Введите количество элементов: ";
                cin >> n;
                cout << "Введите количество позиций для размещения: ";
                cin >> k;
                if (n >= k && k > 0)
                    fl3 = true;
                else
                {
                    cout << "Некорректный ввод" << endl;
                }
            } while (fl3 != true);
            cout << "Количество размещений " << n << " элементов по " << k << " позициям: " << pow(n, k) << endl;
            fl1 = true; break;
        }
        case 2:
        {
            cout << "\t\t/------------------------------------/\n"
                << "\t\t|                                    |\n"
                << "\t\t/  Число размещений без повторением  /\n"
                << "\t\t|                                    |\n"
                << "\t\t/------------------------------------/\n";
            do
            {
                cout << "Введите количество элементов: ";
                cin >> n;
                cout << "Введите количество позиций для размещения: ";
                cin >> k;
                if (n >= k && k > 0)
                    fl3 = true;
                else
                {
                    cout << "Некорректный ввод" << endl;
                }
            } while (fl3 != true);
            cout << "Количество размещений " << n << " элементов по " << k << " позициям: " << factorial(n) / factorial(n - k) << endl;
            fl1 = true; break;
        }
        case 3:
        {
            cout << "\t\t/---------------------------------/\n"
                << "\t\t|                                 |\n"
                << "\t\t/  Число сочетаний c повторением  /\n"
                << "\t\t|                                 |\n"
                << "\t\t/---------------------------------/\n";
            do
            {
                cout << "Введите количество элементов: ";
                cin >> n;
                cout << "Введите количество позиций для сочетания: ";
                cin >> k;
                if (n >= k && k > 0)
                    fl3 = true;
                else
                {
                    cout << "Некорректный ввод" << endl;
                }
            } while (fl3 != true);
            cout << "Количество сочетаний " << n << " элементов по " << k << " позициям: " << factorial(n + k - 1) / (factorial(k) * factorial(k - 1)) << endl;
            fl1 = true; break;
        }
        case 4:
        {
            cout << "\t\t/-----------------------------------/\n"
                << "\t\t|                                   |\n"
                << "\t\t/  Число сочетаний без повторением  /\n"
                << "\t\t|                                   |\n"
                << "\t\t/-----------------------------------/\n";
            do
            {
                cout << "Введите количество элементов: ";
                cin >> n;
                cout << "Введите количество позиций для сочетания: ";
                cin >> k;
                if (n >= k && k > 0)
                    fl3 = true;
                else
                {
                    cout << "Некорректный ввод" << endl;
                }
            } while (fl3 != true);
            cout << "Количество сочетаний " << n << " элементов по " << k << " позициям: " << factorial(n) / (factorial(n - k) * factorial(k)) << endl;
            fl1 = true; break;
        }
        case 5:
        {
            cout << "\t\t/----------------------/\n"
                 << "\t\t|                      |\n"
                 << "\t\t/  Число перестановок  /\n"
                 << "\t\t|                      |\n"
                 << "\t\t/----------------------/\n";
            do
            {
                cout << "Введите количество элементов: ";
                cin >> n;
                if (n > 0)
                    fl3 = true;
                else
                    cout << "Некорректный ввод" << endl;
            } while (fl3 != true);
            cout << "Количество перестановок " << n << " элементов: " << factorial(n) << endl;
            fl1 = true; break;
        }
        }
    } while (fl1 != true);
}
