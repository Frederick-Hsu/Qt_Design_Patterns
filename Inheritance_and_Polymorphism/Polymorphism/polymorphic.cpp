/**************************************************************************************************
 * File name    : polymorphic.cpp
 * Description  : Exercise to investigate the multiple derivations with polymorphism.
 * Creator      : Frederick Hsu
 * Creation date: WWed. 03 April 2019
 * Copyright(C) 2019    All rights reserved.
 * 
 **************************************************************************************************/

#include <iostream>

using namespace std;

class A
{
public:
    A() 
    {
    }
    virtual ~A()
    {
    }
    virtual void foo()
    {
        cout << "A's A::foo()" << endl;
        bar();
    }
    virtual void bar()
    {
        cout << "A's A::bar()" << endl;
    }
};

class B : public A
{
public:
    void foo()
    {
        cout << "B's B::foo()" << endl;
        A::foo();
    }
    void bar()
    {
        cout << "B's B::bar()" << endl;
    }
};

int main(int argc, char* argv[])
{
    B bobj;
    A *aptr = &bobj;
    aptr->foo();
    cout << "--------------------------------" << endl;

    A aobj = *aptr;
    aobj.foo();
    cout << "--------------------------------" << endl;

    aobj = bobj;
    aobj.foo();
    cout << "--------------------------------" << endl;

    bobj.foo();
}