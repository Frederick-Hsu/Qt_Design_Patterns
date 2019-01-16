/**************************************************************************************************
 * Project      : stream
 * Description  : Study the difference between std::iostream and Qt::QTextStream
 * ================================================================================================
 * File name    : main.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederique Hsu
 * Creation date: Thu.  17 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 * 
 **************************************************************************************************/


#include "stream.h"

int main(int argc, char* argv[])
{
    manipulate_std_stream();
    manipulate_qt_stream();
    return 0;
}