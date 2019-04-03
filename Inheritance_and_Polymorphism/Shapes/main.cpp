/**************************************************************************************************
 * Project      : Shapes
 * Description  : Delve the abstract class design and concrete class inheritance.
 * ================================================================================================
 * File name    : main.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederick Hsu
 * Creation date: Wed.  03 April 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/


#include <QCoreApplication>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    executeTestCases();
    getchar();
    // return a.exec();
    return EXIT_SUCCESS;
}
