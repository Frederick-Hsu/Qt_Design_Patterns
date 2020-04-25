#ifndef UNDO_MAIN_WND_H
#define UNDO_MAIN_WND_H

    #include <QMainWindow>
    #include <QUndoStack>

    namespace Ui
    {
        class UndoMainWnd;
    }

    class QLabel;

    class UndoMainWnd : public QMainWindow
    {
        Q_OBJECT
    public:
        explicit UndoMainWnd(QWidget* parent = nullptr);
        ~UndoMainWnd();
    public slots:
        void displayImage(const QImage& img);
    private:
        QLabel* m_ImageDisplay;
        QImage m_Image;
        QUndoStack m_Stack;
    private slots:
        void on_actionAdjust_Color_triggered();
        void on_actionUndo_The_Last_Action_triggered();
        void on_actionHorizontal_Mirror_triggered();
        void on_actionVertical_Mirror_triggered();
        void on_actionQuit_triggered();
        void on_actionSave_triggered();
        void on_actionClose_triggered();
        void on_actionOpen_triggered();

        void on_redoButton_clicked();
        void on_openButton_clicked();
        void on_saveButton_clicked();
        void on_quitButton_clicked();
        void on_adjustColorButton_clicked();
        void on_undoButton_clicked();
        void on_verticalMirrorButton_clicked();
        void on_horizontalMirrorButton_clicked();
    private:
        Ui::UndoMainWnd* ui;
    };

#endif  /* UNDO_MAIN_WND_H */
