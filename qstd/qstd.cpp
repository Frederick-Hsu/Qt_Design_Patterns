/**************************************************************************************************
 * File name    : qstd.cpp
 * Description  : Similar as the <iostream> in std namespace, implement such streamized input / output
 *              : utility functions as cin, cout, cerr in qstd namespace.
 * Creator      : Frederique Hsu
 * Creation date: Wed.  30 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 *  
 **************************************************************************************************/

#include "qstd.h"
#include <QString>
#include <QFile>

QTextStream qstd::cout(stdout, QIODevice::WriteOnly);
QTextStream qstd::cin(stdin, QIODevice::ReadOnly);
QTextStream qstd::cerr(stderr, QIODevice::WriteOnly);

/* Namespace membes are like static class members */
bool qstd::yes(QString question)
{
    QString ans;
    cout << QString(" %1 [y/n]? ").arg(question);
    cout.flush();
    ans = cin.readLine();
    return (ans.startsWith("Y", Qt::CaseInsensitive));
}