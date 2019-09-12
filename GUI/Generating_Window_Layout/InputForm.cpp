#include "InputForm.h"

#include <QSettings>
#include <QVariant>
#include <QColor>
#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QColorDialog>

InputForm::InputForm(QWidget* parent) : QDialog(parent)
{
    QSettings s;
    setWindowTitle("QFormLayout demo");
    QVariant v = s.value("color/favorite", QVariant());
    if (!v.isNull())
    {
        m_color = qvariant_cast<QColor>(v);
    }

    /* start id = "form" */
    m_name = new QLineEdit();
    m_birthday = new QDateEdit();
    m_birthday->setDisplayFormat("yyyy-MM-dd");
    m_colorButton = new QPushButton(tr("Choose"));
    m_colorButton->setAutoFillBackground(true);

    m_buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    QVBoxLayout *vbox = new QVBoxLayout();
    QFormLayout *layout = new QFormLayout;

    layout->addRow(tr("Name"), m_name);
    layout->addRow(tr("Birthday"), m_birthday);
    layout->addRow(tr("Favorite Color"), m_colorButton);

    vbox->addLayout(layout);
    vbox->addWidget(m_buttons);

    Q_ASSERT(vbox->parent() == nullptr);
    Q_ASSERT(m_birthday->parent() == nullptr);
    setLayout(vbox);
    Q_ASSERT(vbox->parent() == this);
    Q_ASSERT(m_birthday->parent() == this);
    /* end */

    connect(m_colorButton, SIGNAL(clicked()), this, SLOT(chooseColor()));
    connect(m_buttons, SIGNAL(accepted()), this, SLOT(accept()));
    connect(m_buttons, SIGNAL(rejected()), this, SLOT(reject()));
    updateUi();
}

void InputForm::updateUi()
{
    QPalette p = m_colorButton->palette();
    p.setColor(QPalette::Button, m_color);
    m_colorButton->setPalette(p);
}

void InputForm::accept()
{
    QSettings s;
    s.setValue("Color/Favorite", qVariantFromValue<QColor>(m_color));

    QDate birthday = m_birthday->date();
    int days = birthday.daysTo(QDate::currentDate());
    QMessageBox::information(this, tr("Age guesser"), tr("You are %1 years-old").arg(days/365));
    QDialog::accept();
}

void InputForm::chooseColor()
{
    m_color = QColorDialog::getColor(m_color, this);
    updateUi();
}
