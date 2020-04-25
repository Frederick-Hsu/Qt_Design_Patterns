/**************************************************************************************************
 * Project      : BlackJack_Game
 * Description  : Design a card game "BlackJack" to let players and dealer play with this game.
 * ================================================================================================
 * File name    : main.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederick Hsu
 * Creation date: Thur. 30 Jan. 2020
 * Copyright(C) 2020    All rights reserved.
 *
 **************************************************************************************************/

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("HelloBike");
    app.setOrganizationDomain("helloglobal.com");
    app.setApplicationName("BlackJack");


    return app.exec();
}
