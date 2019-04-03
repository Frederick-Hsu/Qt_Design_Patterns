#include "Derived.h"
#include <iostream>

using namespace std;

Derived::Derived()
{
    cout << "Derived::Derived()" << endl;
}

void Derived::a()
{
    cout << "Derived::a()" << endl;
    c();
}

void Derived::b()
{
    cout << "Derived::b()" << endl;
}

void Derived::c()
{
    cout << "Derived::c()" << endl;
}
