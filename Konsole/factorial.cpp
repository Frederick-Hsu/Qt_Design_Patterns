/**************************************************************************************************
 * File name    : factorial.cpp
 * Description  : Extract the code to construct a function to calculate the factorial(n).
 * Creator      : Frederick Hsu
 * Creation date: Sat.  05 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 * 
 **************************************************************************************************/

#include <iostream>

using namespace std;

long factorial(long n);

int main(int argc, char* argv[])
{
    cout << "Please enter n: " << endl;
    long n;
    cin >> n;
    
    if (n >= 0)
    {
        long nfact = factorial(n);
        if (nfact < 0)
        {
            cerr << "overflow error: " << n << " is too big." << endl;
        }
        else
        {
            cout << "factorial(" << n << ") = " << nfact << endl;
        }
    }
    else
    {
        cerr << "Undefined: factorial of a negative number : " << n << endl;
    }
    return 0;
}

long factorial(long n)
{
    long ans = 1;
    for (long i = 2; i <= n; i++)
    {
        ans = ans * i;
        if (ans < 0)
        {
            return (-1);
        }
    }
    return ans;
}
