/* Project name : QtGUI_HelloWorld
 * Description  : Write the first Qt UI application of HelloWorld.
 * ================================================================================================
 * File name    : main.cpp
 * Description  : This file implements the main() entry function.
 * Creator      : Frederique Hsu
 * Creation date: Sat.  02 May 2020
 * Copyright(C) 2020    All rights reserved.
 *
 */

#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[])
{
    /* Initialize graphics environment */
    QApplication app(argc, argv);

    QLabel *label = new QLabel;
    label->setText("Hello, this is Qt C++ programming world.");
    label->show();

    return app.exec();
}
