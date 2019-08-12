/**************************************************************************************************
 * Project name : QtObjects
 * Description  : Investigate how Qt manage and organize the objects.
 * ================================================================================================
 * File name    : main.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederick Hsu
 * Creation date: Wed.  07 Aug. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/


#include <QCoreApplication>
#include <iostream>

#include "suffolk_university_organization.h"

int main(int argc, char *argv[])
{
    growBunch();
    std::cout << "We have now returned from growBunch()."
              << "\nWhat happened to Alice?" << std::endl;
    return 0;
}
