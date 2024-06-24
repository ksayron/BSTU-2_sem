﻿#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
    int target1 = 3;
    int num_items1 = std::count(v.begin(), v.end(), target1);
    std::cout << "число: " << target1 << "количество: " << num_items1 << '\n';
    int num_items3 = std::count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });
    std::cout << "Количетсво элементов,кратных 3: " << num_items3 << '\n';
    std::cout << std::endl << "Лямбда,захват переменных" << std::endl;
    for (auto i : v)[i]() {if (i % 3 == 0)std::cout << i << ' '; }();
    std::cout << std::endl << "Лямбда с параметрами" << std::endl;
    for (auto i : v)[](auto i) {if (i % 3 == 0)std::cout << i << ' '; }(i);
    std::cout << std::endl << "Лямбда без параметров" << std::endl;
    for (auto i : v)[i] {if (i % 3 == 0)std::cout << i << ' '; }();

}

