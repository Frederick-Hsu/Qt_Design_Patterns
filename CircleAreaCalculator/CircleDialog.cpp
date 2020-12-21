#include "CircleDialog.hpp"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

static const double PI = 3.1415926;

CCircleDialog::CCircleDialog(QWidget* parent) : QDialog(parent)
{
    i1 = 1;
    m_radiusLabel = new QLabel(this);
    m_radiusLabel->setText(QString(tr("请输入圆的半径：")));
    m_radiusLineEdit = new QLineEdit(this);
    m_areaLabel = new QLabel(this);
    m_areaLabel->setText(tr("圆的面积："));
    m_areaValueLabel = new QLabel(this);
    m_areaValueLabel->setFrameShape(QFrame::Panel);
    m_areaValueLabel->setFrameShadow(QFrame::Sunken);

    m_calculateButton = new QPushButton(this);
    m_calculateButton->setText(tr("显示对应圆的面积："));

    QGridLayout* mainLayout = new QGridLayout(this);
    mainLayout->addWidget(m_radiusLabel, 0, 0);
    mainLayout->addWidget(m_radiusLineEdit, 0, 1);
    mainLayout->addWidget(m_areaLabel, 0, 2);
    mainLayout->addWidget(m_areaValueLabel, 0, 3);
    mainLayout->addWidget(m_calculateButton, 1, 3);

    connect(m_calculateButton, SIGNAL(clicked()), this, SLOT(showArea()));
    connect(m_radiusLineEdit, SIGNAL(textChanged(QString)), this, SLOT(showArea()));
}

CCircleDialog::~CCircleDialog()
{
    if (m_radiusLabel)
        delete m_radiusLabel;
    if (m_areaLabel)
        delete m_areaLabel;
    if (m_radiusLineEdit)
        delete m_radiusLineEdit;
    if (m_calculateButton)
        delete m_calculateButton;
}

void CCircleDialog::showArea()
{
    bool ok;
    QString tempStr;
    QString valueStr = m_radiusLineEdit->text();
    int value = valueStr.toUInt(&ok, 10);
    double area = value * value * PI;
    m_areaValueLabel->setText(tempStr.setNum(area));
}
