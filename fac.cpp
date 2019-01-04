/**************************************************************************************************
 * File name    : fac.cpp
 * Descripption : Computes and prints n! for a given n. 
 *              : Uses several basic elements of C++.
 * Creator      : Frederick Hsu
 * Creation date: Sat.  05 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include <iostream>

int main(int argc, char* argv[])
{
    using namespace std;
    /* Declarations of variables */
    int factArg = 0;
    int fact(1);
    do
    {
        cout << "Factorial of: ";
        cin >> factArg;
        if (factArg < 0)
        {
            cout << "No negative values, please retry." << endl;
        }
    }
    while (factArg < 0);
    
    int i = 2;
    while (i <= factArg)
    {
        fact = fact * i;
        i = i + 1;
    }
    cout << "The Factorial of " << factArg << " is : " << fact << endl;
    return 0;
}
