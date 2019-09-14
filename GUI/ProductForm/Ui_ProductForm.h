#ifndef UI_PRODUCTFORM_H
#define UI_PRODUCTFORM_H

    class QVBoxLayout;
    class QFormLayout;
    class QLabel;
    class QSpacerItem;
    class QDialogButtonBox;
    class QDialog;

    #include <QLineEdit>
    #include <QTextEdit>
    #include <QDateEdit>
    #include <QDoubleSpinBox>

    class Ui_ProductForm;

    class Ui_ProductForm
    {
    public:
        QVBoxLayout* verticalLayout;
        QFormLayout* formLayout;
        QLabel* label;
        QDoubleSpinBox* priceSpinBox;
        QLabel* label_2;
        QLabel* label_3;
        QLineEdit* nameLineEdit;
        QLabel* label_4;
        QTextEdit* descriptionEdit;
        QDateEdit* dateEdit;
        QSpacerItem* verticalSpacer;
        QDialogButtonBox* buttonBox;

        void setupUi(QDialog* ProductForm);
        void retranslateUi(QDialog* ProductForm);
    };

    namespace Ui
    {
        class ProductForm : public Ui_ProductForm {};
    }

#endif  /* UI_PRODUCTFORM_H */
