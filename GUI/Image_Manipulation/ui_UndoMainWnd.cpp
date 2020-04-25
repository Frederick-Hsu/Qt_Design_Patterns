#include "ui_UndoMainWnd.h"

#include <QMainWindow>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QCoreApplication>

void Ui_UndoMainWnd::setupUi(QMainWindow *UndoMainWnd)
{
    QWidget *centralWidget;
    QHBoxLayout* horizontalLayout;
    QVBoxLayout* verticalLayout;

    if (UndoMainWnd->objectName().isEmpty())
    {
        UndoMainWnd->setObjectName(QString::fromUtf8("UndoMainWnd"));
    }
    UndoMainWnd->resize(800, 600);

    actionOpen = new QAction(UndoMainWnd);
    actionOpen->setObjectName(QString::fromUtf8("actionOpen"));

    actionClose = new QAction(UndoMainWnd);
    actionClose->setObjectName(QString::fromUtf8("actionClose"));

    actionSave = new QAction(UndoMainWnd);
    actionSave->setObjectName(QString::fromUtf8("actionSave"));

    actionQuit = new QAction(UndoMainWnd);
    actionQuit->setObjectName(QString::fromUtf8("actionQuit"));

    actionAdjust_Color = new QAction(UndoMainWnd);
    actionAdjust_Color->setObjectName(QString::fromUtf8("actionAdjust_Color"));

    actionVertical_Mirror = new QAction(UndoMainWnd);
    actionVertical_Mirror->setObjectName(QString::fromUtf8("actionVertical_Mirror"));

    actionHorizontal_Mirror = new QAction(UndoMainWnd);
    actionHorizontal_Mirror->setObjectName(QString::fromUtf8("actionHorizontal_Mirror"));

    actionUndo_The_Last_Action = new QAction(UndoMainWnd);
    actionUndo_The_Last_Action->setObjectName(QString::fromUtf8("actionUndo_The_Last_Action"));

    centralWidget = new QWidget(UndoMainWnd);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));

    horizontalLayout = new QHBoxLayout(UndoMainWnd);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    verticalLayout = new QVBoxLayout(UndoMainWnd);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

    m_ImageDisplay = new QLabel(QString(), centralWidget);
    m_ImageDisplay->setObjectName(QString::fromUtf8("m_ImageDisplay"));
    m_ImageDisplay->setMinimumSize(QSize(640, 480));

    /* Open button */
    openButton = new QPushButton(QString("&Open"), centralWidget);
    openButton->setObjectName(QString::fromUtf8("openButton"));
    verticalLayout->addWidget(openButton);
    /* Save button */
    saveButton = new QPushButton(QString("&Save"), centralWidget);
    saveButton->setObjectName(QString::fromUtf8("saveButton"));
    verticalLayout->addWidget(saveButton);
    /* Quit button */
    quitButton = new QPushButton(QString("&Quit"), centralWidget);
    quitButton->setObjectName(QString::fromUtf8("quitButton"));
    verticalLayout->addWidget(quitButton);
    /* Spacer between Quit-button and Undo-button */
    QSpacerItem* vspacer_between_quitButton_and_undoButton = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayout->addItem(vspacer_between_quitButton_and_undoButton);
    /* Undo button */
    undoButton = new QPushButton(QString("UNDO"), centralWidget);
    undoButton->setObjectName(QString::fromUtf8("undoButton"));
    verticalLayout->addWidget(undoButton);
    /* Redo button */
    redoButton = new QPushButton(QString("REDO"), centralWidget);
    redoButton->setObjectName(QString::fromUtf8("redoButton"));
    verticalLayout->addWidget(redoButton);
    /* Spacer between Redo-button and VerticalMirror-button */
    QSpacerItem* vspace_between_redoButton_and_vmirrorButton = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayout->addItem(vspace_between_redoButton_and_vmirrorButton);
    /* Vertical Mirror button */
    verticalMirrorButton = new QPushButton(QString("Vertical Mirror"), centralWidget);
    verticalMirrorButton->setObjectName(QString::fromUtf8("verticalMirrorButton"));
    verticalLayout->addWidget(verticalMirrorButton);
    /* Horizontal Mirror button */
    horizontalMirrorButton = new QPushButton(QString("Horizontal Mirror"), centralWidget);
    horizontalMirrorButton->setObjectName(QString::fromUtf8("horizontalMirrorButton"));
    verticalLayout->addWidget(horizontalMirrorButton);
    /* The Up Spacer under the Horizontal Mirror button */
    QSpacerItem* vspace_under_horizontalButton = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayout->addItem(vspace_under_horizontalButton);
    /* The Down Spacer over Adjust Color button */
    QSpacerItem* vspacer_over_adjustColorButton = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayout->addItem(vspacer_over_adjustColorButton);
    /* Adjust Color button */
    adjustColorButton = new QPushButton(QString("Adjst Color"), centralWidget);
    adjustColorButton->setObjectName(QString::fromUtf8("adjustColorButton"));
    verticalLayout->addWidget(adjustColorButton);

    /* A form-layout to accomodate the RGB color adjustment */
    QFormLayout* formLayout = new QFormLayout();
    formLayout->setObjectName(QString::fromUtf8("formLayout"));

    /* Red double-spin-box*/
    redSpin = new QDoubleSpinBox(centralWidget);
    redSpin->setObjectName(QString::fromUtf8("redSpin"));
    redSpin->setMaximum(10.00);
    redSpin->setSingleStep(0.10);
    redSpin->setValue(1.00);
    /* Red Label */
    redLabel = new QLabel(centralWidget);
    redLabel->setObjectName(QString::fromUtf8("redLabel"));
    /* Green double-spin-box */
    greenSpin = new QDoubleSpinBox(centralWidget);
    greenSpin->setObjectName(QString::fromUtf8("greenSpin"));
    greenSpin->setMaximum(10.00);
    greenSpin->setSingleStep(0.10);
    greenSpin->setValue(1.00);
    /* Green Label */
    greenLabel = new QLabel(centralWidget);
    greenLabel->setObjectName(QString::fromUtf8("greenLabel"));
    /* Blue double-spin-box */
    blueSpin = new QDoubleSpinBox(centralWidget);
    blueSpin->setObjectName(QString::fromUtf8("blueSpin"));
    blueSpin->setMaximum(10.00);
    blueSpin->setSingleStep(0.10);
    blueSpin->setValue(1.00);
    /* Blue label */
    blueLabel = new QLabel(centralWidget);
    blueLabel->setObjectName(QString::fromUtf8("blueLabel"));

    formLayout->setWidget(1, QFormLayout::FieldRole, redSpin);
    formLayout->setWidget(1, QFormLayout::LabelRole, redLabel);
    formLayout->setWidget(2, QFormLayout::FieldRole, greenSpin);
    formLayout->setWidget(2, QFormLayout::LabelRole, greenLabel);
    formLayout->setWidget(5, QFormLayout::FieldRole, blueSpin);
    formLayout->setWidget(5, QFormLayout::LabelRole, blueLabel);
    verticalLayout->addLayout(formLayout);
    horizontalLayout->addWidget(m_ImageDisplay);
    horizontalLayout->addLayout(verticalLayout);

    UndoMainWnd->setCentralWidget(centralWidget);
    /* Menu bar */
    menubar = new QMenuBar(UndoMainWnd);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    /* Menu : File,  Edit */
    QMenu *menuFile, *menuEdit;
    menuFile = new QMenu(QString("&File"), menubar);
    menuFile->setObjectName(QString::fromUtf8("menuFile"));
    menuEdit = new QMenu(QString("&Edit"), menubar);
    menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
    UndoMainWnd->setMenuBar(menubar);
    /* Status bar */
    statusbar = new QStatusBar(UndoMainWnd);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    UndoMainWnd->setStatusBar(statusbar);
    /* Toolbar */
    toolbar = new QToolBar(UndoMainWnd);
    toolbar->setObjectName(QString::fromUtf8("toolbar"));
    UndoMainWnd->addToolBar(Qt::TopToolBarArea, toolbar);

    /* Add actions for menus and toolbar */
    menubar->addAction(menuFile->menuAction());
    menubar->addAction(menuEdit->menuAction());
    /* Menu File contains 4 menu items */
    menuFile->addAction(actionOpen);
    menuFile->addAction(actionClose);
    menuFile->addAction(actionSave);
    menuFile->addAction(actionQuit);
    /* Menu Edit contains 4 menu items */
    menuEdit->addAction(actionAdjust_Color);
    menuEdit->addAction(actionVertical_Mirror);
    menuEdit->addAction(actionHorizontal_Mirror);
    menuEdit->addAction(actionUndo_The_Last_Action);
    /* Toolbar contains the following actions */
    toolbar->addAction(actionOpen);
    toolbar->addAction(actionClose);
    toolbar->addAction(actionSave);
    toolbar->addAction(actionHorizontal_Mirror);
    toolbar->addAction(actionVertical_Mirror);
    toolbar->addAction(actionUndo_The_Last_Action);

    retranslateUi(UndoMainWnd);

    QMetaObject::connectSlotsByName(UndoMainWnd);
}

void Ui_UndoMainWnd::retranslateUi(QMainWindow *UndoMainWnd)
{
    UndoMainWnd->setWindowTitle(QCoreApplication::translate("UndoMainWnd", "Undo-demo Main Window", nullptr));

    actionOpen->setText(QCoreApplication::translate("UndoMainWnd", "Open", nullptr));
    actionOpen->setShortcut(QCoreApplication::translate("UndoMainWnd", "Ctrl+O", nullptr));

    actionClose->setText(QCoreApplication::translate("UndoMainWnd", "Close", nullptr));
    actionClose->setShortcut(QCoreApplication::translate("UndoMainWnd", "Ctrl+C", nullptr));

    actionSave->setText(QCoreApplication::translate("UndoMainWnd", "Save", nullptr));
    actionSave->setShortcut(QCoreApplication::translate("UndoMainWnd", "Ctrl+S", nullptr));

    actionAdjust_Color->setText(QCoreApplication::translate("UndoMainWnd", "Adjust color", nullptr));
    actionAdjust_Color->setShortcut(QCoreApplication::translate("UndoMainWnd", "Ctrl+A", nullptr));

    actionVertical_Mirror->setText(QCoreApplication::translate("UndoMainWnd", "Mirror V-Pixels", nullptr));
    actionVertical_Mirror->setToolTip(QCoreApplication::translate("UndoMainWnd", "Vertically mirror pixels", nullptr));
    actionVertical_Mirror->setShortcut(QCoreApplication::translate("UndoMainWnd", "Ctrl+V", nullptr));

    actionHorizontal_Mirror->setText(QCoreApplication::translate("UndoMainWnd", "Mirror H-Pixels", nullptr));
    actionHorizontal_Mirror->setToolTip(QCoreApplication::translate("UndoMainWnd", "Horizontally mirror pixels", nullptr));
    actionHorizontal_Mirror->setShortcut(QCoreApplication::translate("UndoMainWnd", "Ctrl+H", nullptr));

    actionUndo_The_Last_Action->setText(QCoreApplication::translate("UndoMainWnd", "Undo last action", nullptr));
    actionUndo_The_Last_Action->setToolTip(QCoreApplication::translate("UndoMainWnd", "Undo the last operation user did", nullptr));
    actionUndo_The_Last_Action->setShortcut(QCoreApplication::translate("UndoMainWnd", "Ctrl+U", nullptr));

    redLabel->setText(QCoreApplication::translate("UndoMainWin", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
    "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
    "p, li { white-space: pre-wrap; }\n"
    "</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#f80000;\">Red</span></p></body></html>", nullptr));

    greenLabel->setText(QCoreApplication::translate("UndoMainWin", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
    "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
    "p, li { white-space: pre-wrap; }\n"
    "</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#00f900;\">Green</span></p></body></html>", nullptr));

    blueLabel->setText(QCoreApplication::translate("UndoMainWin", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
    "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
    "p, li { white-space: pre-wrap; }\n"
    "</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#0000f7;\">Blue</span></p></body></html>", nullptr));
}
