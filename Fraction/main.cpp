/**************************************************************************************************
 * Project      : Fraction
 * Description  : Study the topics of class and object.
 * ================================================================================================
 * File name    : main.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederique Hsu
 * Creation date: Mon.  21 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include <QCoreApplication>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    accessStruture();
    accessClassFraction();
    manipulateComplex();
    // return a.exec();
    getchar();
    return 0;
}
