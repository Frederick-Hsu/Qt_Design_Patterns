#include "circle_area_calculator_dialog.hpp"
#include "ui_calculator_dialog.h"

const static double PI = 3.1415926;

CCircleAreaCalculatorDialog::CCircleAreaCalculatorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CCircleAreaCalculatorDialog)
{
    ui->setupUi(this);
}

CCircleAreaCalculatorDialog::~CCircleAreaCalculatorDialog()
{
    delete ui;
}


void CCircleAreaCalculatorDialog::on_calcButton_clicked()
{
    bool ok;
    QString tempStr;
    QString valueStr = ui->radiusLineEdit->text();
    int value = valueStr.toUInt(&ok, 10);
    double area = value * value * PI;
    ui->areaValueLabel->setText(tempStr.setNum(area));
}

void CCircleAreaCalculatorDialog::on_radiusLineEdit_textChanged(const QString &arg1)
{
    bool ok;
    QString tempStr;
    QString valueStr = ui->radiusLineEdit->text();
    int value = valueStr.toUInt(&ok);
    double area = value * value * PI;
    ui->areaValueLabel->setText(tempStr.setNum(area));
}
