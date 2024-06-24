#include <iostream>
#include <string>
#include <Windows.h> 
using namespace std;


struct passport {//труктура для хранения информации о паспортах
    int passport_number;  // Номер паспорта
    string name;          // Имя владельца
    passport* next;       // Указатель на следующий паспорт в цепочке

    passport(int num, const string& resName) : passport_number(num), name(resName), next(nullptr) {}
};


int hashFunction(int key, int tableSize) {// хеш-функция на основе исключающего ИЛИ(XOR)
    return key ^ ((key >> 16) ^ (key >> 8)) % tableSize; //используем XOR для хеширования
}


void insert(passport** table, int tableSize, int passport_number, const string& name) {//вставка нового элемента в таблицу
    int index = hashFunction(passport_number, tableSize); //получаем индекс для вставки
    passport* new_passport = new passport(passport_number, name); //создаем новый элемент
    new_passport->next = table[index]; 
    table[index] = new_passport; //обновляем указатель на начало цепои
}


void remove(passport** table, int tableSize, int passport_number) {//удаление элемента из таблицы
    int index = hashFunction(passport_number, tableSize); //получаем индекс для поиска
    passport* entry = table[index]; //начинаем поиск с начала цепочки
    passport* prev = nullptr;

   
    while (entry != nullptr && entry->passport_number != passport_number) { //ищем нужный элемент или достигаем конца цепочки
        prev = entry; //сохраняем текущий элемент как предыдущий
        entry = entry->next; 
    }

    if (entry == nullptr) {// Если жилец не найден, выводим сообщение и выходим из функции
        cout << "Паспорт не найден" << endl;
        return;
    }

    
    if (prev == nullptr) {//если удаляемый элемент находится в начале списка
        table[index] = entry->next; //обновляем указатель на начало цепочки
    }
    else {
        prev->next = entry->next; //  
    }

    delete entry; // Освобождаем память, выделенную под удаляемого жильца
}


void displayTable(passport** table, int tableSize) {// вывод содержимого хеш-таблицы
    for (int i = 0; i < tableSize; ++i) {
        cout << "Индекс " << i << ": ";
        passport* entry = table[i];
        while (entry != nullptr) {
            cout << "Паспорт № " << entry->passport_number << ": " << entry->name << " -> ";
            entry = entry->next; 
        }
        cout << "nullptr" << endl;
    }
}


void displayMenu() {
    cout << "Выберите вариант:\n";
    cout << "1. добавить паспорт\n";
    cout << "2. Удалить паспорт\n";
    cout << "3. Вывести таблицу\n";
    cout << "4. Выйти\n";
    cout << "Введите ваш выбор: ";
}


int main() {
    system("color 70");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int tableSize = 10; 
    passport* table[tableSize] = { nullptr }; //создание массива указателей на паспорта
    while (true) {
        displayMenu(); 
        int choice;
        cin >> choice; 

        switch (choice) {
        case 1: { 
            int passport_number;
            string name;
            cout << "Введите номер паспорта: ";
            cin >> passport_number;
            cout << "Введите имя владельца: ";
            cin.ignore();  //очистка буфера ввода
            getline(cin, name); 
            insert(table, tableSize, passport_number, name); 
            break;
        }
        case 2: {
            int passport_number;
            cout << "Введите номер паспорта для удаления: ";
            cin >> passport_number;
            remove(table, tableSize, passport_number);
            break;
        }
        case 3: 
            displayTable(table, tableSize); 
            break;
        case 4: 
            cout << "Выход из программы.\n";
            return 0;
        default: 
            cout << "Неверный выбор. Попробуйте еще раз.\n";
            break;
        }
    }

    return 0;
}
