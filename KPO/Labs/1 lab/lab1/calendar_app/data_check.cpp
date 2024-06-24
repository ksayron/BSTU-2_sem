#include "stdapx.h"

int days_in_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

bool date_check(string date) {
    if (date.size() != 8) { return 0; }
    for (int i = 0; i < 8; i++) {
        if (date[i] > '9' || date[i] < '0') { return 0; }
    }
    return 1;
}

bool data_check(int day, int month, int year) {
    bool check = true, check_d = true;
    if (year == 0) { { cout << "”казан неправильный год" << endl; check = false; } }
    if (month < 1 || month > 12) { cout << "”казан неправильный мес€ц" << endl; check = false; }
    if (LEAP_YEAR_CHECK(year) && month == 2 && day == 29) { check_d = true; }
    else if (day > days_in_month[month - 1] || day < 1) { cout << "”казан неправильный день" << endl; check_d = false; }
    if (check && check_d) { return true; }
    else { return false; }
}

bool birthday_datecheck(string date) {
    if (date.size() != 4) { return 0; }
    for (int i = 0; i < 4; i++) {
        if (date[i] > '9' || date[i] < '0') { return 0; }
    }
    return 1;

}

bool birthday_data_check(int day, int month, int year) {
    bool check = true, check_d = true;
    if (month < 1 || month > 12) { cout << "”казан неправильный мес€ц" << endl; check = false; }
    if (LEAP_YEAR_CHECK(year) && month == 2 && day == 29) { check_d = true; }
    else if (day > days_in_month[month - 1] || day < 1) { cout << "”казан неправильный день" << endl; check_d = false; }
    if (check && check_d) { return true; }
    else { return false; }
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

    if (countdown > 0) {
        if (LEAP_YEAR_CHECK(year)) {
            if (month <= 2 && b_month > 2) { countdown++; }
        }
        return countdown;
    }
    else {
        if (LEAP_YEAR_CHECK(year + 1)) {
            if (b_month > 2) { countdown++; }
        }
        return 365 - abs(countdown);
    }
}