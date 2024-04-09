#include <iostream>
#include <iomanip>
#include <limits>
#include <locale.h>
#include <cmath>
#include "fraction.h"
using namespace std;


void work_fraction()
{
    bool fl1 = false;
    int fl2;
    double drob_a_a, drob_a_b, drob_b_a, drob_b_b;
    cout << "Введите числитель первой дроби: ";
    cin >> drob_a_a;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    do
    {
        cout << "Введите знаменатель первой дроби: ";
        cin >> drob_a_b;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (drob_a_b == 0)
            cout << "Некорректный ввод" << endl;
    } while (drob_a_b == 0);
    cout << "Введите числитель второй дроби: ";
    cin >> drob_b_a;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    do
    {
        cout << "Введите знаменатель второй дроби: ";
        cin >> drob_b_b;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (drob_b_b == 0)
            cout << "Некорректный ввод" << endl;
    } while (drob_b_b == 0);
    if (drob_a_a < 0 && drob_a_b < 0)
    {
        drob_a_a = abs(drob_a_a);
        drob_a_b = abs(drob_a_b);
    }
    if (drob_b_a < 0 && drob_b_b < 0)
    {
        drob_b_a = abs(drob_b_a);
        drob_b_b = abs(drob_b_b);
    }
    if (drob_a_b < 0)
    {
        drob_a_b = abs(drob_a_b);
        drob_a_a = -drob_a_a;
    }
    if (drob_b_b < 0)
    {
        drob_b_b = abs(drob_b_b);
        drob_b_a = -drob_b_a;
    }
    if (drob_a_a == 0)
        drob_a_b = 0;
    if (drob_b_a == 0)
        drob_b_b = 0;
    do
    {
        cout << "Выберите операцию над дробями" << endl;
        cout << "1.Сложение" << endl;
        cout << "2.Вычитание" << endl;
        cout << "3.Умножение" << endl;
        cout << "4.Деление" << endl;
        cin >> fl2;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (fl2)
        {
        case 1:
            if (abs(drob_a_b) == abs(drob_b_b))
            {
                cout << "Ответ: " << drob_a_a + drob_b_a << "/" << drob_a_b << endl; fl1 = true;
            }
            else if (drob_a_a == 0 || drob_b_a == 0)
            {
                cout << "Ответ: " << (drob_a_a + drob_b_a) << "/" << (drob_a_b + drob_b_b) << endl; fl1 = true;
            }
            else
            {
                cout << "Ответ: " << (drob_a_a * drob_b_b) + (drob_b_a * drob_a_b) << "/" << drob_a_b * drob_b_b << endl; fl1 = true;
            }
            break;
        case 2:
            if (abs(drob_a_b) == abs(drob_b_b))
            {
                cout << "Ответ: " << drob_a_a - drob_b_a << "/" << drob_a_b << endl; fl1 = true;
            }
            else if (drob_a_a == 0 || drob_b_a == 0)
            {
                cout << "Ответ: " << (drob_a_a - drob_b_a) << "/" << (drob_a_b + drob_b_b) << endl; fl1 = true;
            }
            else
            {
                cout << "Ответ: " << (drob_a_a * drob_b_b) - (drob_b_a * drob_a_b) << "/" << drob_a_b * drob_b_b << endl; fl1 = true;
            }
            break;
        case 3:
            cout << "Ответ: " << (drob_a_a * drob_b_a) << "/" << (drob_a_b * drob_b_b) << endl; fl1 = true; break;
        case 4:
            if (drob_b_a == 0)
            {
                cout << "Операция невозможнна" << endl;
                break;
            }
            cout << "Ответ: " << (drob_a_a * drob_b_b) << "/" << (drob_a_b * drob_b_a) << endl; fl1 = true; break;
        default:
            cout << "Некорректный ввод" << endl;
        }
    } while (fl1 != true);
}