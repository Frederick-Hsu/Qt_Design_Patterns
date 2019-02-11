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

    double x(1.23), y(4.56), z(7.89);
    int i(2), j(5), k(7);
    x += y;
    z *= x;
    cout << "x = " << x << "\tz = " << z
         << "\nx - z = " << x - z << endl;

    cout << "k / i = " << k / i
         << "\tk % i = " << k % i << endl;

    cout << "i = " << i << "\tj = " << j << "\tk = " << k << endl;
    cout << "++k / i = " << ++k / i << endl;
    cout << "i = " << i << "\tj = " << j << "\tk = " << k << endl;
    cout << "i * j-- = " << i * j-- << endl;
    cout << "i = " << i << "\tj = " << j << "\tk = " << k << endl;
    cout << "z / j = " << z / j << endl;

    /* if () ... else  approach */
    if (x * j <= z)
    {
        cout << "(x * j = " << x * j << ") <= (z = " << z << ")" << endl;
    }
    else
    {
        cout << "(x * j = " << x * j << ") > (z = " << z << ")" << endl;
    }

    /* conditional operator approach */
    cout << x * k 
         << ( (x * k < y * j) ? " < " : " >= ")
         << y * j << endl;
    /* When you want to run your application in console command line, DO NOT use this line. 
     * otherwise, you cannot exit smoothly, use "Ctrl+C" to quit forcely.
     */
    // app.exec();      
    return 0;
}