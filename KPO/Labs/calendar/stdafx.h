#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <map>



bool LEAP_YEAR_CHECK(int);

bool data_check(int, int, int);

int DAY_NUMBER(int, int);

bool LEAP_YEAR_DAY(int, int);

bool datecheck(string);

int BIRTHDAY_COUNT(int, int, int, int, int);

bool birthday_datecheck(string);

void MONTH_NUMBER(int);

void HOLIDAY(int , int , int, map<int, string>);

