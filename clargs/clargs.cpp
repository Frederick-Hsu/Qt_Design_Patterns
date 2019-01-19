/**************************************************************************************************
 * File name    : clargs.cpp
 * Description  : Enable the argument list in the console command line.
 * Creator      : Frederique Hsu
 * Creation date: Sat.  19 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 * 
 **************************************************************************************************/

#include <iostream>
#include <cstdlib>

#if 0
    int main(int argc, char* argv[])
    {
        using namespace std;

        cout << "argc = " << argc << endl;
        for (int index = 0; index < argc; index++)
        {
            cout << "argv#" << index << " is " << argv[index] << endl;
        }
        int num = atoi(argv[argc-1]);
        cout << num * 2 << endl;
        
        return EXIT_SUCCESS;
    }
#endif