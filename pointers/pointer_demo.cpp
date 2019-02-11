/**************************************************************************************************
 * File name	: pointer_demo.cpp
 * Description	: Review the usage of pointer *
 * Creator		: Frederick Hsu
 * creation date: Mon.	21 Jan. 2019
 * Copyright(C)	2019	All rights reserved.
 *
 **************************************************************************************************/

#include "pointers.h"
#include <QTextStream>

QTextStream cout(stdout);

int pointTo(void)
{
	int x = 4;
	int *px = 0;
	px = &x;
    cout << "  x = " << x << "\t"
         << "*px = " << *px << "\t"
         << " px = " << px << "\t"
	     << "&px = " << &px << endl;
	
	x = x + 1;
    cout << "  x = " << x << "\t"
         << "*px = " << *px << "\t"
	     << " px = " << px << endl;

	
	*px = *px + 1;
    cout << "  x = " << x << "\t"
         << "*px = " << *px << "\t"
	     << " px = " << px << endl;
	return 0;
}
