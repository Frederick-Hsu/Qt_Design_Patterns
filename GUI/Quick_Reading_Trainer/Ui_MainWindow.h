#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

    #include <QSpinBox>
    #include <QSlider>
    #include <QLCDNumber>
    #include <QLabel>
    #include <QLineEdit>
    #include <QPushButton>
    #include <QGroupBox>

    class QMainWindow;

    class Ui_MainWindow
    {
    public:
        QSpinBox* trialsSpinBox;
        QSlider* exposureSlider;
        QLCDNumber* exposureLCD;
        QSlider* lengthSlider;
        QLCDNumber* lengthLCD;
        QLabel* correctCharFractionLabel;
        QLabel* cumulativeFractionLabel;
        QLineEdit* targetStrLineEdit;
        QLineEdit* responseStrLineEdit;
        QPushButton* startButton;
        QPushButton* nextButton;
        QLabel* targetStrLabel;
        QLabel* respStrLabel;
        QGroupBox *settingsPane;
    public:
        void setupUi(QMainWindow* mainwindow);
        void retranslateUi(QMainWindow* mainwindow);
    };

    namespace Ui
    {
        class MainWindow : public Ui_MainWindow {};
    }

#endif  /* UI_MAINWINDOW_H */
