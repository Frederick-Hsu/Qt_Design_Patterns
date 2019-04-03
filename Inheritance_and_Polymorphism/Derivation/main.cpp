/**************************************************************************************************
 * Project      : Derivation
 * Description  : Research the inheritance topic of OOP in the Qt context.
 * ================================================================================================
 * File name    : main.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederick Hsu
 * Creation date: Wed.  20 March 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/


#include <QCoreApplication>
#include "student_test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testCase_Execute();

    std::getchar();
    // return a.exec();
    return EXIT_SUCCESS;
}
