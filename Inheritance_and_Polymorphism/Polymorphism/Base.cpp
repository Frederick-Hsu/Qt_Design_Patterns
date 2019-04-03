#include "Base.h"
#include <iostream>

using namespace std;

Base::Base()
{
    cout << "Base::Base()" << endl;
    a();
    c();
}

void Base::c(bool condition)
{
    cout << "Base::c()" << endl;
}

void Base::b()
{
    cout << "Base::b()" << endl;
}

void Base::a()
{
    cout << "Base::a()" << endl;
    b();
}