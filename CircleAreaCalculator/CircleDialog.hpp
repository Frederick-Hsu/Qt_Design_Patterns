#ifndef CIRCLE_DIALOG_HPP
#define CIRCLE_DIALOG_HPP

    #include <QDialog>

    #define VAR(num)    int i##num

    #define MYSIGNAL(arg)   #arg
    #define MYSLOT(arg)     #arg

    class QLabel;
    class QLineEdit;

    class CCircleDialog;

    class CCircleDialog : public QDialog
    {
        Q_OBJECT
    public:
        CCircleDialog(QWidget* parent = nullptr);
        ~CCircleDialog();
    public:
        VAR(1);
    private:
        QLabel* m_radiusLabel;
        QLabel* m_areaLabel;
        QLabel* m_areaValueLabel;
        QLineEdit* m_radiusLineEdit;
        QPushButton* m_calculateButton;
    private slots:
        void showArea();
    };

#endif  /* CIRCLE_DIALOG_HPP */
