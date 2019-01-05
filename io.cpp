/**************************************************************************************************
 * File name    : io.cpp
 * Description  : Study the iostream input and output.
 * Creator      : Frederick Hsu
 * Creation date: Sat.  05 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;
    const int THISYEAR = 2019;
    string yourName;
    int birthYear;
    
    cout << "What is your name? " << flush;
    // cin >> yourName;
    getline(cin, yourName);
    
    cout << "What year were you born? ";
    cin >> birthYear;
    
    cout << "Your name is " << yourName
         << " and you are approximately "
         << (THISYEAR - birthYear)
         << " years old. " 
         << endl;
    
    return 0;
}
