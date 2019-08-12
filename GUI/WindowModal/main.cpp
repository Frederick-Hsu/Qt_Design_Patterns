/**************************************************************************************************
 * Project name : WindowModal
 * Description  : Investigate the modal or non-modal for the window in Qt GUI application.
 * ================================================================================================
 * File name    : main.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederick Hsu
 * Creation date: 13 Aug. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include <QApplication>
#include <QtGui>
#include <QProgressDialog>
#include <QFileDialog>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QProgressDialog nonModal;
    nonModal.setWindowTitle("Non Modal Parent Dialog");
    nonModal.show();
    nonModal.connect(&nonModal,
                     SIGNAL(finished()),
                     &app,
                     SLOT(quit()),
                     Qt::ConnectionType::AutoConnection);

    QFileDialog fileDialog(&nonModal, "Modal file child-dialog");
    /* 2 modal dialogs.exec() takes over all user interactions until closed. */
    fileDialog.exec();
    QMessageBox::question(nullptr,
                          QObject::tr("Modal parentless dialog"),
                          QObject::tr("Can you interact with the other dialogs now?"),
                          QMessageBox::Yes | QMessageBox::No);

    return app.exec();
}
