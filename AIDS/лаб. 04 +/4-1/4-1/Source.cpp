#include <iostream>
#include <string>
using namespace std;

void sort(int* arr, int size)
{
	int min = arr[0];

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				min = arr[i];
				arr[i] = arr[j];
				arr[j] = min;
			}
		}
	}
}


void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int a, max_sum = 0;
	cout << "Введите количество товаров: ";

	
	while (true)
	{
		
		cout << "Введите количество(от 1 до 10000) :";
		cin >> a;


		if (a > 0 && a < 10000)
		{
			break;
		}
		else
		{
			cout << "Введите количество( от 1 до 10000) : ";
			cin>>a;
		}
	}

	cout << "\nцены товаров: \n";

	int* arr = new int[a];


	for (int i = 0; i < a; i++)
	{
		arr[i] = rand() % 100 + 1;
		cout << arr[i] << " ";
	}

	cout << "\n\nпорядок пробивания: " << endl;

	sort(arr, a); 

	int begin = 0, end = a - 1;

	for (int i = 0; i < a; i++)
	{
		if ((i + 1) % 2 == 0)
		{
			cout << arr[begin++] << " "; 
		}
		else
		{
			max_sum += arr[end];
			cout << arr[end--] << " "; 
		}
	}
	cout << "\nМакс сумма чека: " << max_sum;

	cout << endl << endl;

	delete[] arr;

}