#ifndef UI_KEY_SEQUENCE_LABEL_H
#define UI_KEY_SEQUENCE_LABEL_H

    #include <QAction>
    #include <QLabel>
    #include <QLCDNumber>
    #include <QPushButton>
    #include <QMenuBar>
    #include <QMenu>
    #include <QStatusBar>

    class QMainWindow;

    class Ui_KeySequenceLabel
    {
    public:
        QAction* quitAction;
        QAction* showObjectBrowserAction;
        QLabel* numberLabel;
        QLabel* dispLabel;
        QLCDNumber* ledDigits;
        QPushButton* clearBtn;
        QMenuBar* menuBar;
        QMenu* fileMenu;
        QMenu* toolsMenu;
        QStatusBar* _statusBar;

        void setupUi(QMainWindow* window);
        void retranslateUi(QMainWindow* window);
    };

    namespace Ui
    {
        class KeySequenceLabel : public Ui_KeySequenceLabel {};
    }

#endif  /* UI_KEY_SEQUENCE_LABEL_H */
