#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h> 
#include <chrono>

// Функция сортировки пузырьком
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Функция  сортировки Хоара
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Функция для заполнения массива случайными числами
void fillArray(std::vector<int>& arr) {
    for (int& i : arr) {
        i = rand() % 100; // Генерируем случайное число от 0 до 99
    }
}

int main() {
    system("color 70");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::vector<int> sizes = { 1000, 2000, 3000, 4000, 5000 };

    for (int n : sizes) {
        std::vector<int> A(n), B;
        fillArray(A);

        for (int i = 0; i < A.size() - 1; i++) {
            if (i % 2 != 0 && A[i + 1] % 2 != 0) {
                B.push_back(A[i]);
            }
        }

        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(B);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Пузырьковая сортировка для  " << n << " элементов заняла " << duration.count() << " мс.\n" << std::endl;

        start = std::chrono::high_resolution_clock::now();
        quickSort(B, 0, B.size() - 1);
        stop = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Сортировка Хоара для  " << n << " элементов заняла " << duration.count() << " мс.\n\n" << std::endl;
    }

    return 0;
}
