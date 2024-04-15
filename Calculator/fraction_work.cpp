#include <iostream>
#include <iomanip>
#include <limits>
#include <locale.h>
#include <cmath>
#include "fraction.h"
using namespace std;


void NOD(double drob_a, double drob_b)
{
    int buffer = 1, nod = 0;
    while (drob_a >= buffer && drob_b >= buffer)
    {
        if ((drob_a / buffer == int(drob_a / buffer)) && (drob_b / buffer == int(drob_b / buffer)))
        {
            nod = buffer;
        }
        buffer++;
    }
    cout << "Ответ: " << drob_a / nod << "/" << drob_b / nod << endl;
}

void work_fraction()
{
    bool fl1 = false;
    int fl2, fl3;
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
        cout << "5.Сравнение" << endl;
        cout << "6.Сокращение" << endl;
        cout << "7.Представление в виде десятичной дроби" << endl;
        cin >> fl2;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (fl2)
        {
        case 1:
        {
            cout << "\t\t/-------------------/\n"
                << "\t\t|                   |\n"
                << "\t\t/  Сложение дробей  /\n"
                << "\t\t|                   |\n"
                << "\t\t/-------------------/\n";

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
        }
        case 2:
        {
            cout << "\t\t/--------------------/\n"
                << "\t\t|                    |\n"
                << "\t\t/  Вычитание дробей  /\n"
                << "\t\t|                    |\n"
                << "\t\t/--------------------/\n";

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
        }
        case 3:
        {
            cout << "\t\t/--------------------/\n"
                << "\t\t|                    |\n"
                << "\t\t/  Умножение дробей  /\n"
                << "\t\t|                    |\n"
                << "\t\t/--------------------/\n";
        }
            cout << "Ответ: " << (drob_a_a * drob_b_a) << "/" << (drob_a_b * drob_b_b) << endl; fl1 = true; break;
        case 4:
        {
            cout << "\t\t/------------------/\n"
                << "\t\t|                  |\n"
                << "\t\t/  Деление дробей  /\n"
                << "\t\t|                  |\n"
                << "\t\t/------------------/\n";

            if (drob_b_a == 0)
            {
                cout << "Операция невозможнна" << endl;
                break;
            }
            cout << "Ответ: " << (drob_a_a * drob_b_b) << "/" << (drob_a_b * drob_b_a) << endl; fl1 = true; break;
        }
        case 5:
        {
            cout << "\t\t/--------------------/\n"
                << "\t\t|                    |\n"
                << "\t\t/  Сравнение дробей  /\n"
                << "\t\t|                    |\n"
                << "\t\t/--------------------/\n";

            if ((drob_a_a / drob_a_b > drob_a_b) > (drob_b_a / drob_b_b))
                cout << "Первая дробь больше второй" << endl;
            else if ((drob_a_a / drob_a_b > drob_a_b) < (drob_b_a / drob_b_b))
            {
                cout << "Вторая дробь больше первой" << endl;
            }
            else
            {
                cout << "Дроби равны" << endl;
            }
            fl1 = true; break;
        }
        case 6:
        {
            cout << "\t\t/---------------------/\n"
                << "\t\t|                     |\n"
                << "\t\t/  Сокращение дробей  /\n"
                << "\t\t|                     |\n"
                << "\t\t/---------------------/\n";

            cout << "Выберите дробь для сокращения" << endl;
            cout << "1." << drob_a_a << "/" << drob_a_b << endl;
            cout << "2." << drob_b_a << "/" << drob_b_b << endl;
            cout << "3.Обе" << endl;
            do
            {
                cin >> fl3;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                switch (fl3)
                {
                case 1:
                {
                    NOD(drob_a_a, drob_a_b);
                    break;
                }
                case 2:
                {
                    NOD(drob_b_a, drob_b_b);
                    break;
                }
                case 3:
                {
                    NOD(drob_a_a, drob_a_b);
                    NOD(drob_b_a, drob_b_b);
                    break;
                }
                default: cout << "Некорретный ввод!" << endl;
                }
            } while (fl3 != 1 && fl3 != 2 && fl3 != 3);
            fl1 = true; break;
        }
        case 7:
        {
            cout << "\t\t/-----------------------------------------/\n"
                 << "\t\t|                                         |\n"
                 << "\t\t/  Представление в виде десятичной дроби  /\n"
                 << "\t\t|                                         |\n"
                 << "\t\t/-----------------------------------------/\n";

            cout << "Выберите дробь для сокращения" << endl;
            cout << "1." << drob_a_a << "/" << drob_a_b << endl;
            cout << "2." << drob_b_a << "/" << drob_b_b << endl;
            cout << "3.Обе" << endl;
            do
            {
                cin >> fl3;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                switch (fl3)
                {
                case 1:
                {
                    cout << "Ответ: " << drob_a_a / drob_a_b << endl;
                    break;
                }
                case 2:
                {
                    cout << "Ответ: " << drob_b_a / drob_b_b << endl;
                    break;
                }
                case 3:
                {
                    cout << "Ответ: " << drob_a_a / drob_a_b << " ; " << drob_b_a / drob_b_b << endl;
                    break;
                }
                default: cout << "Некорретный ввод!" << endl;
                }
            } while (fl3 != 1 && fl3 != 2 && fl3 != 3);
            fl1 = true; break;
        }
        default:
            cout << "Некорректный ввод" << endl;
        }
    } while (fl1 != true);
}