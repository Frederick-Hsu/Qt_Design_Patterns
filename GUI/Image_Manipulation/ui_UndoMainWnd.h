#ifndef UI_UNDO_MAIN_WND_H
#define UI_UNDO_MAIN_WND_H

    #include <QAction>
    #include <QLabel>
    #include <QPushButton>
    #include <QDoubleSpinBox>
    #include <QMenuBar>
    #include <QStatusBar>
    #include <QToolBar>

    class QMainWindow;

    class Ui_UndoMainWnd
    {
    public:
        QAction* actionOpen;
        QAction* actionClose;
        QAction* actionSave;
        QAction* actionQuit;

        QAction* actionAdjust_Color;
        QAction* actionVertical_Mirror;
        QAction* actionHorizontal_Mirror;
        QAction* actionUndo_The_Last_Action;

        QLabel* m_ImageDisplay;

        QPushButton* openButton;
        QPushButton* saveButton;
        QPushButton* quitButton;
        QPushButton* undoButton;
        QPushButton* redoButton;
        QPushButton* verticalMirrorButton;
        QPushButton* horizontalMirrorButton;
        QPushButton* adjustColorButton;

        QLabel *redLabel, *greenLabel, *blueLabel;
        QDoubleSpinBox* redSpin;
        QDoubleSpinBox* greenSpin;
        QDoubleSpinBox* blueSpin;

        QMenuBar* menubar;
        QStatusBar* statusbar;
        QToolBar* toolbar;
    public:
        void setupUi(QMainWindow* UndoMainWnd);
        void retranslateUi(QMainWindow* UndoMainWnd);
    };

    namespace Ui
    {
        class UndoMainWnd : public Ui_UndoMainWnd {};
    }

#endif  /* UI_UNDO_MAIN_WND_H */
