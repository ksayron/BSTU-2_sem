#include "stdafx.h"

bool LEAP_YEAR_CHECK(int year) {
    if (year % 400 == 0) { return true; }
    if (year % 4 == 0 and year % 100 != 0) { return true; }
    return false;
}

bool LEAP_YEAR_DAY(int year, int month) {
    if (year % 4 == 0 && month >= 2) { return true; }
    else { return false; }
}
