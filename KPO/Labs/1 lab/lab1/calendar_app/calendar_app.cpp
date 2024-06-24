﻿#include "stdapx.h"



int main()
{
    setlocale(LC_CTYPE, "Russian");
    system("color 70");
    string date;
    int day, month, year, dateint, k = 0;
    bool date_check = false;
    cout << "Введите дату в формате ДДММГГГГ:";

    while (k != 4) {

        while (!date_check) {

            cin.clear();
            cin >> date;
            date_check = datecheck(date);
            if (!date_check) { cout << "Повторите ввод даты в формате ДДММГГГГ:"; }
            else {
                dateint = stoi(date);
                day = dateint / 1000000;
                month = (dateint / 10000) % 100;
                year = dateint % 10000;
                date_check = data_check(day, month, year);
                if (!date_check) { cout << "Повторите ввод даты в формате ДДММГГГГ:"; }
            }

        }

        cout << "1 – определение является ли год високосным; " << endl;
        cout << "2 – определение номера дня в году;" << endl;
        cout << "3 – вычислить сколько дней осталось до дня рождения" << endl;
        cout << "4 – выход из программы." << endl;
        cin >> k;
        switch (k)
        {
        case 1:
        {
            cout << endl << "Идёт проверка..." << endl;
            if (LEAP_YEAR_CHECK(year)) { cout << year << " является вискосным годом!" << endl << endl; }
            else { cout << year << " не является вискосным годом!" << endl << endl; }
        }break;
        case 2:
        {
            cout << endl << "Идёт проверка..." << endl;
            if (LEAP_YEAR_DAY(year, month)) { cout << ' ' << day << '.' << month << " является " << DAY_NUMBER(day, month) + 1 << " днём в году!" << endl << endl; }
            else { cout << ' ' << day << '.' << month << " является " << DAY_NUMBER(day, month) << " днём в году!" << endl << endl; }

        }break;
        case 3:
        {
            string birthday_date;
            int b_day, b_month, b_dateint;
            cout << "Введите дату дня рождения в формате ДДММ:";


            date_check = false;
            while (!date_check) {
                cin >> birthday_date;
                date_check = birthday_datecheck(birthday_date);
                if (!date_check) { cout << "Повторите ввод даты в формате ДДММ:"; }
                else {
                    b_dateint = stoi(birthday_date);
                    b_day = b_dateint / 100;
                    b_month = b_dateint % 100;
                    date_check = birthday_data_check(b_day, b_month, year);
                    if (!date_check) { cout << "Повторите ввод даты в формате ДДММ:"; }
                    else if ((BIRTHDAY_COUNT(day, month, year, b_day, b_month)) < 1000) { cout << "До следующего дня рождения осталось: " << BIRTHDAY_COUNT(day, month, year, b_day, b_month) << " дней!"; }
                }

            }
        }break;
        case 4:
        {
            cout << "Благодарим за пользование нашей продукцией!" << endl << endl;
            return 0;
        }break;
        default:
        {
            cout << "Вами была введена неопазнаная комманда. Для использования данного продукта используйте цифры 1-4" << endl;
            cout << "Повторите ваш ввод" << endl << endl;
        }
        }
    }

}