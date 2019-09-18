/**************************************************************************************************
 * File name    : Thing.cpp
 * Description  : Implement the class Thing, which contains static member.
 * Creator      : Frederick Hsu
 * Creation date: Thu.  24 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include "Thing.h"
#include <iostream>

int Thing::s_Count = 0;

Thing::Thing(int a, int b) : m_First(a), m_Second(b)
{
    ++s_Count;
}

Thing::~Thing()
{
    --s_Count;
}

void Thing::display() const
{
    std::cout << m_First << "$$" << m_Second << std::endl;
}

void Thing::showCount()
{
    std::cout << "Count = " << s_Count << std::endl;
}

long nextNumber(void)
{
    long localVar(24);
    static long statNum = 1000;
    std::cout << statNum + localVar << std::endl;
    return ++statNum;
}
