#include <iostream>
#include "vector.h"
using std::cout;

int foo(int n)
{
    int m[n];
    return sizeof(m);
}

int main()
{
    int n;
    std::cin >> n;
    foo(n);
}