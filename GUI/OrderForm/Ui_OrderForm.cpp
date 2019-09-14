#include "Ui_OrderForm.h"

#include <QDialog>
#include <QFormLayout>
#include <QLabel>
#include <QSizePolicy>

void Ui_OrderForm::setupUi(QDialog *OrderForm)
{
    if (OrderForm->objectName().isEmpty())
    {
        OrderForm->setObjectName("OrderForm");
    }
    OrderForm->setWindowTitle(QString("Order info."));
    OrderForm->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);

    QFormLayout* formLayout = new QFormLayout();

    QLabel* nameLabel = new QLabel(QString("Name"), OrderForm);
    nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
    formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

    nameEdit = new QLineEdit(OrderForm);
    nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
    formLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);

    QLabel* dateLabel = new QLabel(QString("Date Added"), OrderForm);
    dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
    formLayout->setWidget(1, QFormLayout::LabelRole, dateLabel);

    dateEdit = new QDateEdit(QDate::currentDate(), OrderForm);
    dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
    formLayout->setWidget(1, QFormLayout::FieldRole, dateEdit);

    QLabel* qtyLabel = new QLabel(QString("Quantity"), OrderForm);
    qtyLabel->setObjectName(QString::fromUtf8("qtyLabel"));
    formLayout->setWidget(2, QFormLayout::LabelRole, qtyLabel);

    qtySpinBox = new QSpinBox(OrderForm);
    qtySpinBox->setObjectName(QString::fromUtf8("qtySpinBox"));
    formLayout->setWidget(2, QFormLayout::FieldRole, qtySpinBox);

    QLabel* unitpriceLabel = new QLabel(QString("Unit Price"), OrderForm);
    unitpriceLabel->setObjectName(QString::fromUtf8("unitpriceLabel"));
    formLayout->setWidget(3, QFormLayout::LabelRole, unitpriceLabel);

    unitpriceSpinBox = new QDoubleSpinBox(OrderForm);
    unitpriceSpinBox->setObjectName(QString::fromUtf8("unitpriceSpinBox"));
    formLayout->setWidget(3, QFormLayout::FieldRole, unitpriceSpinBox);

    QLabel* totalpriceLabel = new QLabel(QString("Total Price"), OrderForm);
    totalpriceLabel->setObjectName(QString::fromUtf8("totalpriceLabel"));
    formLayout->setWidget(4, QFormLayout::LabelRole, totalpriceLabel);

    totalpriceSpinBox = new QDoubleSpinBox(OrderForm);
    totalpriceSpinBox->setObjectName(QString::fromUtf8("totalpriceSpinBox"));
    formLayout->setWidget(4, QFormLayout::FieldRole, totalpriceSpinBox);

    QVBoxLayout* vboxLayout = new QVBoxLayout(OrderForm);
    vboxLayout->addLayout(formLayout);
    vboxLayout->addStretch(1);

    okcancelBtnBox = new QDialogButtonBox(Qt::Horizontal, OrderForm);
    okcancelBtnBox->setObjectName(QString::fromUtf8("okcancelBtnBox"));
    okcancelBtnBox->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    vboxLayout->addWidget(okcancelBtnBox);

    QObject::connect(okcancelBtnBox, SIGNAL(accepted()), OrderForm, SLOT(accept()));
    QObject::connect(okcancelBtnBox, SIGNAL(rejected()), OrderForm, SLOT(reject()));
    QMetaObject::connectSlotsByName(OrderForm);
}
