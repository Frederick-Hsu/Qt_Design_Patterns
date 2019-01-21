/**************************************************************************************************
 * File name    : FactorialGUI.cpp
 * Description  : This demonstrates how to build a simple Qt GUI application.
 * Creator      : Frederick Hsu
 * Creation date: Thu.  17 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 * 
 **************************************************************************************************/

#include <QtGui>
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QTextStream cout(stdout);

    int answer;
    do
    {
        int factArg = 0;
        unsigned long long fact(1);
        factArg = QInputDialog::getInt(0, "Factorial Calculator", "Factorial of: ", 1);
        cout << "user entered: " << factArg << endl;

        int i = 2;
        while (i <= factArg)
        {
            fact = fact * i;
            ++i;
        }

        QString response = QString("The factorial of %1 is %2.\n%3").arg(factArg)
                                                                    .arg(fact)
                                                                    .arg("Do you want to compute another factorial?");
        answer = QMessageBox::question(0, "Play again?", response, QMessageBox::Yes|QMessageBox::No);
    }
    while (answer == QMessageBox::Yes);
    return EXIT_SUCCESS;
}