#include <iostream>
#include "func.h"

namespace Call
{
    int _cdecl func1(int a, int b, int c)
    {
        return a + b + c;
    }
    int _stdcall cstd(int& a, int b, int c)
    {
        return a * b * c;
    }
    int _fastcall cfst(int a, int b, int c, int d)
    {
        return a + b + c + d;
    }
}

int main()
{
    int x = 2;
    int k1 = Call::func1(3, 4, 5);

    int k2 = Call::cstd(x, 3, 4);

    int k3 = Call::cfst(1, 2, 3, 4);


}