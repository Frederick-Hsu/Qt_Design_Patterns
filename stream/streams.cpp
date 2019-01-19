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

    cout << "Read data from the file - watch for errors." << endl;
    string newstr;
    ifstream inf;
    inf.open("mydata");
    if (inf)    /* Make sure the file exists before attempting to read. */
    {
        int lucky2;
        inf >> newstr >> lucky2;
        if (lucky != lucky2)
        {
            cerr << "ERROR! wrong " << newstr << lucky2 << endl;
        }
        else
        {
            cout << newstr << " OK" << endl;
        }

        float pi2;
        inf >> newstr >> pi2;
        if (pi2 != pi)
            cerr << "ERROR! wrong " << newstr << pi2 << endl;
        else
            cout << newstr << " OK" << endl;
        
        double e2 ;
        inf >> newstr >> e2;
        if (e2 != e)
        {
            cerr << "ERROR : wrong " << newstr << e2 << endl;
        }
        else
        {
            cout << newstr << " OK" << endl;
        }
        inf.close();
    }

    cout << "Read from file line-by-line" << endl;
    inf.open("mydata");
    if (inf)
    {
        while (not inf.eof())
        {
            getline(inf, newstr);
            cout << newstr << endl;
        }
        inf.close();
    }
}