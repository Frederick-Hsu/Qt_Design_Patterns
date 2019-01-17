/**************************************************************************************************
 * File name    : qt_stream_demo.cpp
 * Description  : Study how to manipulate the stream based on Qt::QTextStream.
 * Creator      : Frederique Hsu
 * Creation date: Thu.  17 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 * 
 **************************************************************************************************/

#include "stream.h"
#include <QTextStream>
#include <QDebug>

QTextStream cin(stdin);
QTextStream cout(stdout);
QTextStream cerr(stderr);

void manipulate_qt_stream(void)
{
    int num1(1234), num2(2345);
    cout << oct << "0" << num2 << '\t'
         << hex << "0x" << num2 << '\t'
         << dec << num2 << endl;

    // cout << boolalpha << (num1 << num2) << endl;

    double dub(1357);
    cout << dub << '\t'
         << forcesign << dub << '\t'
         << forcepoint << dub << endl;

    dub = 1234.5678;
    cout << dub << '\t'
         << fixed << dub << '\t'
         << scientific << dub << '\n'
         << noforcesign << dub << endl;

    qDebug() << "Here is a debug message with " << dub << "in it.";
    qDebug("Here is one with the number %d in it.", num1);
}