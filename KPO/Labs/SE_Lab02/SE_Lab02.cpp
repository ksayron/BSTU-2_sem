// SE_Lab02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int sum(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int (*f)(int, int );

int main()
{
    bool first = 0, second=1;//0x006FFAC3 0x006FFAB7
    char sim = 'u'; //0x012FF877 
    char sim_rus = 'у';//0x012FF86B
    wchar_t sim2 = L'u';//0x012FF85C
    wchar_t sim2_rus = L'у';

    short mini = 18;//0x12 0x006FFA78
    short neg_mini = -18;//ee ff 0x006FFA6C 
 
    short smax = SHRT_MAX;//32767 
    short smin = -SHRT_MIN;//-32767 
    unsigned short usmax=USHRT_MAX;//65535 
    unsigned short usmin = 0; 

    int iplus = 19;//0x13 0x006FFA30
    int iminus = -19;// ed ff ff ff

    int imax = INT32_MAX;//2147483647
    int imin = INT32_MIN;//-2147483648

    unsigned int uimax=UINT32_MAX;//4294967295
    unsigned int uimin = 0;

    long lnplus = 20;//0x14
    long lnminus = -20;//ec ff ff ff

    long lnmax = LONG_MAX;//2147483647	
    long lnmin = LONG_MIN;//-2147483648

    unsigned long ulmax = ULONG_MAX;//4294967295
    unsigned long ulmin = 0;

    float fplus = 10.0;//0x41 20
    float fminus = -10.0;//0xc1 20

    float f1 = 23.625f;
    float f2 = -23.625f;
    float infpl = f1/0;
    float infmin = f2 / 0;
    double indif = sqrt(-1);

    char* pc = &sim;
    wchar_t* pwc = &sim2;
    int* pin = &iplus;
    float* pf = &fplus;

    char* pc1 = &sim+3;
    wchar_t* pwc1 = &sim2+3;
    int* pin1 = &iplus+3;
      float* pf1 = &fplus+3;

    f = sum;
    int res1 = f(iplus, iminus);

    f = sub;
    int res2 = f(iplus, iminus);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
