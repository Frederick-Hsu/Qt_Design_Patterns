/**************************************************************************************************
 * Project      : qstd
 * Description  : Demonstrate how to utilize the Qt style iostream.
 * ================================================================================================
 * File name    : qtio_demo.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederique Hsu
 * Creation date: Wed.  30 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 * 
 **************************************************************************************************/

#include <qstd.h>
#include <QDate>

using namespace qstd;

int main(int argc, char* argv[])
{
    QDate d1(2018, 9, 13), d2(QDate::currentDate());
    int days;

    cout << "The first date is : " << d1.toString()
         << "\nToday's date is : " << d2.toString("ddd MMM dd, yyyy")
         << endl;

    if (d1 < d2)
    {
        cout << d1.toString("MM/dd/yy") << " is earlier than "
             << d2.toString(Qt::ISODate) << endl;
    }

    cout << "Enter number of days to add to the first date: " << flush;
    days = promptInt();
    cout << "The first date was : " << d1.toString()
         << "\nThe computed date is " << d1.addDays(days).toString()
         << endl;
    cout << "First date displayed in longer format : " 
         << d1.toString("dddd, MMMM dd, yyyy")
         << endl;
    
    return 0;
}