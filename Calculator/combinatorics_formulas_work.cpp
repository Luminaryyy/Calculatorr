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
        cout << "1.Число перестановок" << endl;
        cout << "2.Число размещений" << endl;
        cout << "3.Число сочетаний" << endl;
        cout << "0.Для выхода из комбинаторики" << endl;
        cin >> fl2;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (fl2)
        {
        case 1:
        {
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
            break;
        }
        case 2:
        {
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
            cout << "Количество размещентий " << n << " элементов по " << k << " позициям: " << factorial(n) / factorial(n - k) << endl;
        }
        case 3:
        {
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
        }
        }
    } while (fl1 != true);
}