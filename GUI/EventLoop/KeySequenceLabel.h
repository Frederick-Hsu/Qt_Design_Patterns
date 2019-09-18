#ifndef KEY_SEQUENCE_LABEL_H
#define KEY_SEQUENCE_LABEL_H

    #include <QMainWindow>
    #include <QList>
    #include <QPair>
    #include "Ui_KeySequenceLabel.h"

    class QObjectBrowserAction;
    class QEvent;
    class QKeyEvent;
    class QPaintEvent;
    class QTimerEvent;

    class KeySequenceLabel : public QMainWindow, private Ui::KeySequenceLabel
    {
        Q_OBJECT
    public:
        KeySequenceLabel(QWidget* parent = nullptr);
    private:
        QObjectBrowserAction* m_browserAction;
        QList<QPair<int, int> > m_keys;
        int m_paints;
    protected:
        void changeEvent(QEvent* e);
        void keyPressEvent(QKeyEvent*);
        void leaveEvent(QEvent*);
        void enterEvent(QEvent*);
        void paintEvent(QPaintEvent*);
        void timerEvent(QTimerEvent*);
        void updateUi();
    private slots:
        void on_showObjectBrowser_triggered(bool checked);
        void on_clearBtn_clicked();
        void on_quitAction_triggered();
    };

#endif  /* KEY_SEQUENCE_LABEL_H */
