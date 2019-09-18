/**************************************************************************************************
 * File name    : qsize.cpp
 * Description  : Demonstrate how to calculate the memory size where type and object occupy.
 * Creator      : Frederique Hsu
 * Creation date: Thu.  17 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 * 
 **************************************************************************************************/

#include <QString>
#include <QTextStream>
#include <QChar>
#include <QDate>

int main(int argc, char* argv[])
{
    QTextStream cout(stdout);
    char array1[34] = "This is a dreaded C array of char";
    char array2[] = "if not for main, we could avoid entirely.";
    char* charp = array1;
    QString qstring = "This is a unicode QString. Much preferred.";
    int i = 1;
    Q_ASSERT(sizeof(i) == sizeof(int));

    cout << "  c type sizes: \n";
    cout << "sizeof(char) = " << sizeof(char) << '\n';
    cout << "sizeof(wchar_t) = " << sizeof(wchar_t) << '\n';
    cout << "sizeof(int) = " << sizeof(int) << '\n';
    cout << "sizeof(long) = " << sizeof(long) << '\n';
    cout << "sieof(float) = " << sizeof(float) << '\n';
    cout << "sizeof(double) = " << sizeof(double) << '\n';
    cout << "sizeof(double*) = " << sizeof(double*) << '\n';
    cout << "sizeof(array1) = " << sizeof(array1) << '\n';
    cout << "sizeof(array2) = " << sizeof(array2) << '\n';
    cout << "sizeof(char*) = " << sizeof(charp) << "\n";

    cout << "\n" << endl;
    
    cout << "  qt type sizes: \n";
    cout << "sizeof(QString) = " << sizeof(QString) << endl;
    cout << "sizeof(qint32) = " << sizeof(qint32) << "\n";
    cout << "sizeof(qint64) = " << sizeof(qint64) << '\n';
    cout << "sizeof(QChar) = " << sizeof(QChar) << endl;
    cout << "sizeof(QDate) = " << sizeof(QDate) << endl;
    cout << "qstring.length() = " << qstring.length() << endl;
    return 0;
}