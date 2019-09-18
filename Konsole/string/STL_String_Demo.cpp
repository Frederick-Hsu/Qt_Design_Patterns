/**************************************************************************************************
 * File name    : STL_String_Demo.cpp
 * Description  : Demonstrate how to utilize the string in the STL style.
 * Creator      : Frederick Hsu
 * Creation date: Tue.  15 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 * 
 **************************************************************************************************/

#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    string s1("This "), s2("is a "), s3("string.");
    s1 += s2;
    string s4 = s1 + s3;
    cout << s4 << endl;
    string s5("The length of that string is : ");
    cout << s5 << s4.length() << " characters." << endl;

    cout << "Enter a sentence: " << endl;
    getline(cin, s2);
    cout << "Here is your sentence: \n" << s2 << endl;
    cout << "The length of your sentence is : " << s2.length() << endl;
    return 0;
}