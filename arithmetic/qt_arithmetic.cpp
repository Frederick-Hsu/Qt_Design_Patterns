/**************************************************************************************************
 * File name    : qt_arithmetic.cpp
 * Description  : Study how to make the arithmetic calculation in Qt C++ program.
 * Creator      : Frederick Hsu
 * Creation date: Sun.  20 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 * 
 **************************************************************************************************/

#include <QTextStream>
#include <QCoreApplication>

QTextStream cout(stdout);

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    /* When you want to run your application in console command line, DO NOT use this line. 
     * otherwise, you cannot exit smoothly, use "Ctrl+C" to quit forcely.
     */
    // app.exec();      
}