#include "Ui_KeySequenceLabel.h"

#include <QCoreApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>

void Ui_KeySequenceLabel::setupUi(QMainWindow* window)
{
    if (window->objectName().isEmpty())
    {
        window->setObjectName(QString("window"));
    }
    window->setWindowTitle(QString("Event Loop Demo"));

    quitAction = new QAction(QString("&Quit"), window);
    quitAction->setObjectName(QString("quitAction"));

    showObjectBrowserAction = new QAction(window);
    showObjectBrowserAction->setObjectName(QString("showObjectBrowserAction"));
    showObjectBrowserAction->setCheckable(true);

    QWidget* centerWidget = new QWidget(window);
    centerWidget->setObjectName(QString("centerWidget"));

    QVBoxLayout* vLayout = new QVBoxLayout(window);
    vLayout->setSpacing(6);
    vLayout->setContentsMargins(10, 10, 10, 10);

    numberLabel = new QLabel(QString("Number of paintEvents()"), window);
    ledDigits = new QLCDNumber(141, window);
    ledDigits->setObjectName(QString("ledDigits"));

    QHBoxLayout* hTopLayout = new QHBoxLayout();
    hTopLayout->addWidget(numberLabel, 2);
    hTopLayout->addWidget(ledDigits, 2);

    clearBtn = new QPushButton(QString("Clear"), window);
    clearBtn->setObjectName(QString("clearBtn"));
    dispLabel = new QLabel(QString("QKeySequence"));

    QHBoxLayout* hBottomLayout = new QHBoxLayout();
    hBottomLayout->addWidget(clearBtn, 1);
    hBottomLayout->addWidget(dispLabel, 3);

    vLayout->addLayout(hTopLayout);
    vLayout->addLayout(hBottomLayout);

    menuBar = new QMenuBar(window);
    menuBar->setObjectName(QString("menuBar"));
    fileMenu = new QMenu(QString("&File"), menuBar);
    fileMenu->setObjectName(QString("fileMenu"));
    fileMenu->addAction(quitAction);

    toolsMenu = new QMenu(QString("&Tools"), menuBar);
    toolsMenu->setObjectName(QString("toolsMenu"));
    toolsMenu->addAction(showObjectBrowserAction);

    menuBar->addAction(fileMenu->menuAction());
    menuBar->addAction(toolsMenu->menuAction());
    window->setMenuBar(menuBar);

    _statusBar = new QStatusBar(window);
    _statusBar->setObjectName(QString("_statusBar"));
    window->setStatusBar(_statusBar);

    QMetaObject::connectSlotsByName(window);
}

void Ui_KeySequenceLabel::retranslateUi(QMainWindow *window)
{
    window->setWindowTitle(QCoreApplication::translate("KeySequenceLabel", "Event Loop Demo", nullptr));
    quitAction->setText(QCoreApplication::translate("KeySequenceLabel", "Quit", nullptr));
#if QT_CONFIG(shortcut)
    quitAction->setShortcut(QCoreApplication::translate("KeySequenceLabel", "Ctrl+Q", nullptr));
#endif
    showObjectBrowserAction->setText(QCoreApplication::translate("KeySequenceLabel", "Show ObjectBrowser", nullptr));
    numberLabel->setText(QCoreApplication::translate("KeySequenceLabel", "Number of paintEvents()", nullptr));
    clearBtn->setText(QCoreApplication::translate("KeySequenceLabel", "Clear", nullptr));
    dispLabel->setText(QCoreApplication::translate("KeySequenceLabel", "QKeySequence", nullptr));
    fileMenu->setTitle(QCoreApplication::translate("KeySequenceLabel", "File", nullptr));
    toolsMenu->setTitle(QCoreApplication::translate("KeySequenceLabel", "Tools", nullptr));
}
