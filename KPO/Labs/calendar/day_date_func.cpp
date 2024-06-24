#include "stdafx.h"

int days_in_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

string months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

bool datecheck(string date) {
    if (date.size() != 8) { cout << "Проверьте размер введеной даты" << endl; return 0; }
    for (int i = 0; i < 8; i++) {
        if (date[i] > '9' || date[i] < '0') { cout << "Для ввода используются лишь цифры"<<endl; return 0; }
    }
    return 1;
}

bool data_check(int day, int month, int year) {
    bool check = true, check_d = true;
    if (year == 0) { { cout << "Указан неправильный год" << endl; check = false; } }
    if (month < 1 || month > 12) { cout << "Указан неправильный месяц" << endl; check = false; }
    if (LEAP_YEAR_CHECK(year)) { days_in_month[1] = 29; }
    else{ days_in_month[1] = 28; }
    if ((day > days_in_month[month - 1] || day < 1) && check) { cout << "Указан неправильный день" << endl; check_d = false; }
    if (check && check_d) {  return true; }
    else { return false; }
}

bool birthday_datecheck(string date) {
    if (date.size() != 4) { return 0; }
    for (int i = 0; i < 4; i++) {
        if (date[i] > '9' || date[i] < '0') { return 0; }
    }
    return 1;

}

int DAY_NUMBER(int day, int month) {
    int count = 0;
    for (int i = 0; i < month - 1; i++) {
        count += days_in_month[i];
    }
    count += day;
    return count;
}

int BIRTHDAY_COUNT(int day, int month, int year, int b_day, int b_month) {
    int countdown;
    countdown = DAY_NUMBER(b_day, b_month) - DAY_NUMBER(day, month);
    if (countdown == 0) { cout << "HAPPY BIRTHDAY!!!"; return 1000; }

    if (countdown > 0) {return countdown;}
    else {
        if (LEAP_YEAR_CHECK(year + 1)) {
            if (b_month > 2) { countdown++; }
        }
        return 365 - abs(countdown);
    }
}

void MONTH_NUMBER(int n) {
    cout << endl << months[n - 1]<<endl;
}

void HOLIDAY(int day,int month,int year,map<int,string> holidays) {
    auto result = holidays.find(DAY_NUMBER(day, month));
    if (result->first != 256) { result->first - LEAP_YEAR_CHECK(year); }
    if (result != holidays.end()) {
        cout << "Сегодня празднуется " << result->second<<endl<<endl;
    }
}

