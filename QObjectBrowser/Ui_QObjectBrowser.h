/**************************************************************************************************
 * File name    : Ui_QObjectBrowser.h
 * Description  : Define the UI of QObjectBrowser.
 * Creator      : Frederique Hsu
 * Creation date: Sat.  18 April 2020
 * Copyright(C) 2020    All rights reserved.
 *
 **************************************************************************************************/

#ifndef UI_QOBJECTBROWSER_H
#define UI_QOBJECTBROWSER_H

    #include <QWidget>
    #include <QLabel>
    #include <QPushButton>
    #include <QTabWidget>
    #include <QTableWidget>

QT_BEGIN_NAMESPACE

    class Ui_QObjectBrowser
    {
    public:
        /* UI controls */
        QLabel* classnameLabel;
        QLabel* baseclassnameLabel;
        QPushButton* uptoprentButton;
        QLabel* parentclassnameLabel;

        QTabWidget* tabGroup;
        QPushButton* updatechildrenButton;
        QPushButton* updatepropertiesButton;
        QTableWidget* childrenTable;
        QTableWidget* propertiesTable;
        QTableWidget* signalsTable;
        QTableWidget* slotsTable;
        QTableWidget* methodsTable;
    public:
        void setupUi(QWidget* qobjectbrowser);
    };

    namespace Ui
    {
        class QObjectBrowser : public Ui_QObjectBrowser {};
    }

QT_END_NAMESPACE

#endif  /* UI_QOBJECTBROWSER_H */
