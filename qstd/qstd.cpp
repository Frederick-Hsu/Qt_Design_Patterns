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

bool qstd::more(QString prompt)
{
    return yes(QString("Another %1").arg(prompt));
}

int qstd::promptInt(int base)   /* Usage : int n = promptInt(); */
{
    QString numstr;
    int result;
    bool ok;
    cout << " : " << flush;
    while (true)
    {
        numstr = cin.readLine();
        result = numstr.toInt(&ok, base);
        if (!ok)
        {
            cout << "Invalid number. Try again : ";
            cout.flush();
        }
        else
        {
            return result;
        }
    }
}

double qstd::promptDouble()
{
    QString numstr;
    double result;
    bool ok;
    while (1)
    {
        numstr = cin.readLine();
        result = numstr.toDouble(&ok);
        if (!ok)
        {
            cout << "Invalid number. Try again : ";
            cout.flush();
        }
        else
        {
            return result;
        }
    }
}

void qstd::promptOutputFile(QFile& outfile)
{
    QString filename;
    while (1)
    {
        cout << "Please enter the file name you want to save this data : ";
        cout.flush();
        filename = cin.readLine();
        outfile.setFileName(filename);
        if (!outfile.exists())
        {
            break;
        }
        if (qstd::yes("File already exists ... Okay to overwrite"))
        {
            break;
        }
    }
    outfile.open(QIODevice::WriteOnly);
    cout << filename << " open for writing ... " << endl;
}

void qstd::promptInputFile(QFile& infile)
{
    QString filename;
    while (1)
    {
        cout << "Name of the file to be read : ";
        cout.flush();
        filename = cin.readLine();
        infile.setFileName(filename);
        if (infile.exists())
        {
            infile.open(QIODevice::ReadOnly);
            break;
        }
        cout << "File does not exist ... Please try again." << endl;
    }
    cout << infile.fileName() << " open for reading ...\n" << endl;
}