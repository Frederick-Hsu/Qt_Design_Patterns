/**************************************************************************************************
 * File name    : std_stream_demo.cpp
 * Description  : Study how to manipulate the stream based on std::iostream
 * Creator      : Frederique Hsu
 * Creation date: Thu.  17 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 * 
 **************************************************************************************************/

#include "stream.h"
#include <iostream>

using namespace std;

void manipulate_std_stream(void)
{
    int num1(1234), num2(2345);
    std::cout << std::oct << "0" << num2 << '\t'
              << std::hex << "0x" << num2 << '\t'
              << std::dec << num2 << std::endl;

    cout << (num1 < num2) << endl;
    cout << boolalpha << (num1 < num2) << endl;

    double dub(1357);
    cout << dub << '\t'
         << showpos << dub << '\t'
         << showpoint << dub << endl;

    dub = 1234.5678;
    cout << dub << '\t'
         << fixed << dub << '\t'
         << scientific << dub << '\n'
         << noshowpos << dub << endl;
}