/**************************************************************************************************
 * Project name : ArgumentList
 * Description  : Delve the derivation mechanism and how to design a reusable class.
 * ================================================================================================
 * File name    : main.cpp
 * Description  : This file implements the entry function main() for current project.
 * Creator      : Frederick Hsu
 * Creation date: Thu.  23 May 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include <QCoreApplication>
#include "ArgumentList.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    ArgumentList al(argc, argv);
    QString appname = al.takeFirst();
    qDebug() << "Running " << appname;
    bool verbose = al.getSwitch("-v");
    bool testing = al.getSwitch("-t");
    if (testing)
    {
        runTestOnly(al, verbose);
        return 0;
    }
    else
    {
        qDebug() << "This is NOT A Test.";
    }

    // return a.exec();
    getchar();
    return 0;
}
