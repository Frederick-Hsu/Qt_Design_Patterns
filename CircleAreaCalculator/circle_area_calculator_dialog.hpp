#ifndef CCIRCLEAREACALCULATORDIALOG_HPP
#define CCIRCLEAREACALCULATORDIALOG_HPP

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class CCircleAreaCalculatorDialog; }
QT_END_NAMESPACE

class CCircleAreaCalculatorDialog : public QDialog
{
    Q_OBJECT

public:
    CCircleAreaCalculatorDialog(QWidget *parent = nullptr);
    ~CCircleAreaCalculatorDialog();

private slots:
    void on_calcButton_clicked();

    void on_radiusLineEdit_textChanged(const QString &arg1);

private:
    Ui::CCircleAreaCalculatorDialog *ui;
};
#endif // CCIRCLEAREACALCULATORDIALOG_HPP
