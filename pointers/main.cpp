/**************************************************************************************************
 * Project      : pointers
 * Description  : This project deserved to delve the pointer topic in Qt C++
 * ================================================================================================
 * File name    : main.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederick Hsu
 * Creation date: Mon.  21 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include <QCoreApplication>
#include "pointers.h"
#include "pointer_accessing_memory.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    pointTo();
    newDeletePointers();
    referenceVariable();
    constantPointerAndReference();

    getchar();
    // return a.exec();
    return 0;
}
