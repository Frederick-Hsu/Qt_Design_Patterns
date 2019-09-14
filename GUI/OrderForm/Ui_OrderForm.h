#ifndef UI_ORDERFORM_H
#define UI_ORDERFORM_H

    #include <QLineEdit>
    #include <QDateEdit>
    #include <QSpinBox>
    #include <QDoubleSpinBox>
    #include <QDialogButtonBox>

    class Ui_OrderForm
    {
    public:
        QLineEdit* nameEdit;
        QDateEdit* dateEdit;
        QSpinBox* qtySpinBox;
        QDoubleSpinBox* unitpriceSpinBox;
        QDoubleSpinBox* totalpriceSpinBox;
        QDialogButtonBox* okcancelBtnBox;

        void setupUi(QDialog* OrderForm);
    };

    namespace Ui
    {
        class OrderForm : public Ui_OrderForm
        {
        };
    }

#endif  /* UI_ORDERFORM_H */
