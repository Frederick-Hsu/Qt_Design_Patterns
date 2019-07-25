/**************************************************************************************************
 * Project      : LibraryApp
 * Description  : Construct a comprehensive application to summary up the inheritance and polymorphism.
 * ================================================================================================
 * File name    : main.cpp
 * Description  : This file implements the entry function main() for current project.
 * Creator      : Frederique Hsu
 * Creation date: Fri.  24 May 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/


#include <QCoreApplication>
#include "Library.h"
#include "LibraryClient.h"

int main(int argc, char *argv[])
{
    Library lib;
    bool saved;
    while (1)
    {
        switch (nextTask())
        {
        case READ:
            read(lib);
            saved = false;
            break;
        case ADD:
            enterData(lib);
            saved = false;
            break;
        case FIND:
            find(lib);
            break;
        case REMOVE:
            remove(lib);
            saved = false;
            break;
        case SAVE:
            save(lib);
            saved = true;
            break;
        case LIST:
            list(lib);
            break;
        case QUIT:
            prepareToQuit(lib);
            break;
        default:
            break;
        }
    }
}
