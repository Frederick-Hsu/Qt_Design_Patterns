/**************************************************************************************************
 * Project      : Polymorphism
 * Description  : Study the topic of polymorphism in C++ OOP.
 * ================================================================================================
 * File name    : main.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederick Hsu
 * Creation date: Wed.  03 April 2019
 * Copyright(C) 2019    All rights reserved.
 * 
 **************************************************************************************************/

#include "Base.h"
#include "Derived.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    Base b;
    Derived d;

    cout << "Objects created : " << endl;
    b.b();
    cout << "Calling derived methods" << endl;
    d.a();
    d.b();
    d.c();

    cout << "... via base class pointers ..." << endl;
    Base *bp = &d;
    bp->a();
    bp->b();
    bp->c();

    return 0;
}