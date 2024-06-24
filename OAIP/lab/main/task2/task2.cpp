#include <iostream>
#include <ctime> // Для работы с временем
#include <cstdlib> // Для функции rand()
#include <Windows.h>
using namespace std;

// Функция для пузырьковой сортировки
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) { // Проходим по всему массиву
        for (int j = 0; j < n - 1 - i; ++j) { // Внутренний цикл для пары элементов
            if (arr[j] > arr[j + 1]) { // Если элемент слева больше элемента справа
                // Обмен значениями
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Функция для слияния двух подмассивов
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1; // Размер левого подмассива
    int n2 = r - m; // Размер правого подмассива

    // Создаем временные массивы для хранения значений
    int* L = new int[n1];
    int* R = new int[n2];

    // Копируем данные из оригинального массива во временные массивы
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    // Индексы для прохода по временным массивам
    int i = 0, j = 0, k = l;

    // Объединяем временные массивы обратно в основной массив
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        }
        else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Копируем оставшиеся элементы из L[], если есть
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Копируем оставшиеся элементы из R[], если есть
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    // Освобождаем временные массивы
    delete[] L;
    delete[] R;
}

// Функция для сортировки слиянием
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Находим середину массива

        // Рекурсивно сортируем первую и вторую половины
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Сливаем отсортированные половины
        merge(arr, l, m, r);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    

    return 0;
}
