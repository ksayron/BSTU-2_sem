#include <iostream>

using namespace std;
typedef unsigned short day;
typedef unsigned short month;
typedef unsigned short year;
struct Date {
    day dd;
    month mm;
    year yyyy;
};

//перегрузка < 
bool operator < (Date date1, Date date2) {
    return ((date1.yyyy < date2.yyyy) || (date1.yyyy == date2.yyyy && date1.mm < date2.mm) || (date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd < date2.dd));
}
//перегрузка >
bool operator > (Date date1, Date date2) {
    return ((date1.yyyy > date2.yyyy) || (date1.yyyy == date2.yyyy && date1.mm > date2.mm) || (date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd > date2.dd));
}
//перегрузка ==
bool operator == (Date date1, Date date2) {
    return (date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd == date2.dd);
}

int main() {
    setlocale(LC_ALL, "RUS");

    Date date1 = { 7,1,1980 };
    Date date2 = { 7,2,1993 };
    Date date3 = { 7,1,1980 };

    cout << (date1 < date2 ? "истина" : "ложь") << endl;
    cout << (date1 > date2 ? "истина" : "ложь") << endl;
    cout << (date1 == date2 ? "истина" : "ложь") << endl;
    cout << (date1 == date3 ? "истина" : "ложь") << endl;

    return 0;
}
