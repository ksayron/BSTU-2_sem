#include "stdafx.h"

bool LEAP_YEAR_CHECK(int year) {
    if (year % 4 == 0) { return true; }
    else { return false; }
}

bool LEAP_YEAR_DAY(int year, int month) {
    if (year % 4 == 0 && month >= 2) { return true; }
    else { return false; }
}
