/**************************************************************************************************
 * File name    : overload.cpp
 * Description  : Study how to overload the functions in C++.
 * Creator      : Frederick Hsu
 * Creation date: Sat.  12 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 * 
 **************************************************************************************************/

#include <iostream>

using namespace std;

/* Functions prototype */
void foo(int n);
void foo(double x);
void foo(bool b);

int main(int argc, char *argv[])
{
    cout << "before call : " << 5 << endl;
    foo(5);

    cout << "before call : " << 6.7 << endl;
    foo(6.7);

    cout << "before call : " << true << endl;
    foo(true);
    return 0;
}

void foo(int n)
{
    cout << n << " is a nice int." << endl;
}

void foo(double x)
{
    cout << x << " is a nice double." << endl;
}

void foo(bool b)
{
    cout << "Always be " << (b ? "true" : "flase") << endl;
}