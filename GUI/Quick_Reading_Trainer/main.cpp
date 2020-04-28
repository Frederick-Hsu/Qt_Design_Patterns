/**************************************************************************************************
 * Project name : Quick_Reading_Trainer
 * Description  : Write a comprehensive UI of MainWindow, adopting the QTimer to trigger event.
 * ================================================================================================
 * File name    : main.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederick Hsu
 * Creation date: Wed.  23 Oct. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow window;
    window.show();

    return a.exec();
}
