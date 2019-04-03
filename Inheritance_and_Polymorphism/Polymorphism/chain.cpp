/**************************************************************************************************
 * File name    : chain.cpp
 * Description  : Study how the inheritance chain works.
 * Creator      : Frederick Hsu
 * Creation date: Wed.  03 April 2019
 * Copyright(C) 2019    All rights reserved.
 * 
 **************************************************************************************************/

#include <iostream>

using namespace std;

class A
{
public:
    virtual void foo()
    {
        cout << "A's A::foo()" << endl;
    }
};

class B : public A
{
public:
    void foo()
    {
        cout << "B's B::foo()" << endl;
    }
};

class C : public B
{
public:
    void foo()
    {
        cout << "C's C::foo()" << endl;
    }
};

int main(int argc, char* argv[])
{
    C cobj;
    B *bptr = &cobj;
    bptr->foo();

    A* aptr = &cobj;
    aptr->foo();
    return 0;
}