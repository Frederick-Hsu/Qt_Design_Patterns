#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

    #include <QMainWindow>

    #include "RandomString.h"

    class Ui_MainWindow;

    class MainWindow : public QMainWindow
    {
        Q_OBJECT
    public:
        explicit MainWindow(QWidget* parent = nullptr);
        ~MainWindow();
    protected:
        void changeEvent(QEvent* e);
        void processTrial();
    private:
        Ui_MainWindow* ui;
    private slots:
        void on_startButton_clicked();
        void on_nextButton_clicked();
        void on_responseString_returnPressed();
        void on_lengthSlider_valueChanged(int value);
        void on_exposureSlider_valueChanged(int value);
        void timerDisplayRandStr();
    private:
        int m_expInterval;
        RandomString m_randStr;
        int m_trials;
        int m_correctChars;
        int m_totalTrials;
        int m_totalCorrectChars;
    };

#endif  /* MAIN_WINDOW_H */
