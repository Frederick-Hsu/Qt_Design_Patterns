#ifndef INPUT_FORM_H
#define INPUT_FORM_H

    #include <QDialog>

    class QLineEdit;
    class QDateEdit;
    class QPushButton;
    class QDialogButtonBox;

    class InputForm : public QDialog
    {
        Q_OBJECT
    public:
        explicit InputForm(QWidget* parent = nullptr);
        void updateUi();
    protected:
        void accept();
        void chooseColor();
    private:
        QColor m_color;
        QLineEdit *m_name;
        QDateEdit *m_birthday;
        QPushButton *m_colorButton;
        QDialogButtonBox *m_buttons;
    };

#endif  /* INPUT_FORM_H */
