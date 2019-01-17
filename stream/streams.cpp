/**************************************************************************************************
 * File name    : streams.cpp
 * Description  : Implement how to manipulate the file stream.
 * Creator      : Frederique Hsu
 * Creation date: Thu.  17 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 * 
 **************************************************************************************************/

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void manipulate_std_file_stream(void)
{
    ostringstream strbuf;

    int lucky = 7;
    float pi = 3.1415926;
    double e = 2.71;

    cout << "An in-memory stream" << endl;
    strbuf << "lucky number : " << lucky << endl
           << "pi : " << pi << endl
           << "e : " << e << endl;

    string strval = strbuf.str();
    cout << strval;

    ofstream outf;
    outf.open("mydata");
    outf << strval;
    outf.close();
}