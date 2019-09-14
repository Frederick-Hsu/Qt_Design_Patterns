#include "Ui_ProductForm.h"

#include <QApplication>
#include <QDialog>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QSpacerItem>
#include <QDialogButtonBox>

void Ui_ProductForm::setupUi(QDialog *ProductForm)
{
    if (ProductForm->objectName().isEmpty())
    {
        ProductForm->setObjectName(QString::fromUtf8("ProductForm"));
    }
    // ProductForm->resize(257, 209);

    formLayout = new QFormLayout();
    formLayout->setObjectName(QString::fromUtf8("formLayout"));

    label_4 = new QLabel(ProductForm);      /* Name label */
    label_4->setObjectName(QString::fromUtf8("label_4"));
    formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

    nameLineEdit = new QLineEdit(ProductForm);
    nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
    formLayout->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

    label = new QLabel(ProductForm);        /* Price label */
    label->setObjectName(QString::fromUtf8("label"));
    formLayout->setWidget(1, QFormLayout::LabelRole, label);

    priceSpinBox = new QDoubleSpinBox(ProductForm);
    priceSpinBox->setObjectName(QString::fromUtf8("priceSpinBox"));
    formLayout->setWidget(1, QFormLayout::FieldRole, priceSpinBox);

    label_2 = new QLabel(ProductForm);      /* Description label */
    label_2->setObjectName(QString::fromUtf8("label_2"));
    formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

    descriptionEdit = new QTextEdit(ProductForm);
    descriptionEdit->setObjectName(QString::fromUtf8("descriptionEdit"));
    formLayout->setWidget(2, QFormLayout::FieldRole, descriptionEdit);

    label_3 = new QLabel(ProductForm);      /* DateValid label */
    label_3->setObjectName(QString::fromUtf8("label_3"));
    formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

    dateEdit = new QDateEdit(ProductForm);
    dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
    formLayout->setWidget(3, QFormLayout::FieldRole, dateEdit);

    verticalLayout = new QVBoxLayout(ProductForm);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->addLayout(formLayout);

    verticalSpacer = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayout->addItem(verticalSpacer);

    buttonBox = new QDialogButtonBox(ProductForm);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
    label->setBuddy(priceSpinBox);
#endif  /* QT_NO_SHORTCUT */

    retranslateUi(ProductForm);

    QObject::connect(buttonBox, SIGNAL(accepted()), ProductForm, SLOT(accept()), Qt::AutoConnection);
    QObject::connect(buttonBox, SIGNAL(rejected()), ProductForm, SLOT(reject()), Qt::AutoConnection);
    QMetaObject::connectSlotsByName(ProductForm);
}

void Ui_ProductForm::retranslateUi(QDialog *ProductForm)
{
    ProductForm->setWindowTitle(QApplication::translate("ProductForm", "Product Form", nullptr));
    label->setText(QApplication::translate("ProductForm", "&Price", nullptr));
    label_2->setText(QApplication::translate("ProductForm", "Description", nullptr));
    label_3->setText(QApplication::translate("ProductForm", "DateValid", nullptr));
    label_4->setText(QApplication::translate("ProductForm", "Name", nullptr));
}
