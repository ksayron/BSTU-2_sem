#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

typedef int accNumber;
typedef std::string accowner;
typedef bool operationType;
typedef int operationSum;
typedef unsigned short day;
typedef unsigned short month;
typedef unsigned short year;
struct Date {
    day dd;
    month mm;
    year yyyy;
};


struct AccountHolder {
    accowner Name;
    accNumber Number;
};


struct Operation {
    AccountHolder accounts;
    operationType type;
    operationSum sum;
    Date date;
};

bool operator ==(AccountHolder a, AccountHolder b) {
    return a.Name == b.Name ;
}

bool operator ==(Operation a, Operation b) {
    return a.sum == b.sum;
}


bool operator <(Operation a, Operation b) {
    return a.sum < b.sum;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int numHolders;
    cout << "Введите количество операций: ";
    cin >> numHolders;

    Operation* opers = new Operation[numHolders];

    for (int i = 0; i < numHolders; ++i) {
        cin.ignore();
        cout << "Введите ФИО владельца счета " << i + 1 << ": ";
        getline(cin, opers[i].accounts.Name);

        cout << "Введите номер счета " << i + 1 << ": ";
        cin>> opers[i].accounts.Number;

        cout << "Введите желаемую операцию (0-снятие 1-пополнение): ";
        cin>>opers[i].type;

        cout << "Введите на какую сумму выполняется операция " << i + 1 << ": ";
        cin >> opers[i].sum;

        cout << "Введите дату операции: ";
        cin >> opers[i].date.dd>> opers[i].date.mm>> opers[i].date.yyyy;

    }

    for (int i = 0; i < numHolders; ++i) {
        cout << "Владелец " << i + 1 << ":" << endl;
        cout << "ФИО: " << opers[i].accounts.Name << endl;
        cout << "Номер счета: " << opers[i].accounts.Number << endl;
        cout << (opers[i].type ? "Пополнение" : "Снятие") << endl;
        cout << "Сумма операции: " << opers[i].sum << endl;
        cout << "Сумма операции: " << opers[i].date.dd << ' ' << opers[i].date.mm << ' ' << opers[i].date.yyyy << endl;
    }
    if (opers[0].accounts == opers[1].accounts) {
        cout << "Владельцы счетов имеют одинаковое имя" << endl;
    }
    else {
        cout << "Владельцы счетов имеют разные имена" << endl;
    }

    // Применение оператора <
    if (opers[0] < opers[1]) {
        cout << "Операция 1 проводилась на меньшую сумму,чем операция 2" << endl;
    }
    else if(opers[0] == opers[1]){
        cout << "Операция 1 проводилась на ту же сумму,чем операция 2" << endl;
    }
    else {
        cout << "Операция 1 проводилась на большую сумму,чем операция 2" << endl;
    }

    
    delete[] opers;

    return 0;
}
