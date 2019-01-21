/**************************************************************************************************
 * File name    : qt_stream_demo.cpp
 * Description  : Study how to manipulate the stream based on Qt::QTextStream.
 * Creator      : Frederique Hsu
 * Creation date: Thu.  17 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 * 
 **************************************************************************************************/

#include "stream.h"
#include "file_stream.h"

#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QFile>

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

void manipulate_qt_file_stream(void)
{
     QString str, newstr;
     QTextStream strbuf(&str);

     int lucky = 7;
     float pi = 3.1415926;
     double e = 2.71;

     cout << "An in-memory stream" << endl;
     strbuf << "lucky number : " << lucky << endl
            << "pi : " << pi << endl
            << "e : " << e << endl;
     cout << str;

     QFile data("mydata");
     data.open(QIODevice::ReadOnly);
     QTextStream out(&data);
     out << str;
     data.close(); 

     cout << "Read data from the file - watch for errors." << endl;
     if (data.open(QIODevice::ReadOnly))
     {
          QTextStream in(&data);
          int lucky2;
          in >> newstr >> lucky2;
          if (lucky != lucky2)
          {
               cerr << "ERROR! wrong " << newstr << lucky2 << endl;
          }
          else
          {
               cout << newstr << " OK" << endl;
          }

          float pi2;
          in >> newstr >> pi2;
          if (pi2 != pi)
               cerr << "ERROR! wrong " << newstr << pi2 << endl;
          else
               cout << newstr << " OK" << endl;
          
          double e2;
          in >> newstr >> e2;
          if (e2 != e)
          {
               cerr << "ERROR: wrong " << newstr << e2 << endl;
          }
          else
          {
               cout << newstr << " OK" << endl;
          }
          data.close();
     }      

     cout << "Read from file line-by-line" << endl;
     if (data.open(QIODevice::ReadOnly))
     {
          QTextStream in(&data);
          while (not in.atEnd())
          {
               newstr = in.readLine();
               cout << newstr << endl;
          }
          data.close();
     }     
}