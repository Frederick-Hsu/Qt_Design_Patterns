#include "MainWindow.h"
#include "Ui_MainWindow.h"

#include <QEvent>
#include <QTimer>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow),
                                          m_expInterval(0),
                                          m_randStr(),
                                          m_trials(0),
                                          m_correctChars(0),
                                          m_totalTrials(0),
                                          m_totalCorrectChars(0)
{
    ui->setupUi(this);
    ui->nextButton->hide();
    m_randStr.setStringLength(5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_exposureSlider_valueChanged(int value)
{
    ui->exposureLCD->display(value);
    m_expInterval = value;
}

void MainWindow::on_lengthSlider_valueChanged(int value)
{
    ui->lengthLCD->display(value);
    m_randStr.setStringLength(value);
}

void MainWindow::on_startButton_clicked()
{
    ui->startButton->hide();    /* Hide the start button */
    /* Show game panel */
    ui->nextButton->show();
    ui->settingsPane->setEnabled(false);    /* Disable settings */

    m_trials = 0;
    m_correctChars = 0;
    /* Start trials */
    processTrial();
}

void MainWindow::on_nextButton_clicked()
{
    int goodChars(m_randStr.numCorrectChars(ui->responseStrLineEdit->text()));
    int lenTarget = static_cast<int>(ui->lengthLCD->value());
    m_correctChars += goodChars;
    m_totalCorrectChars += goodChars;

    ui->correctCharFractionLabel->setText(QString("%1 / %2").arg(m_correctChars).arg(lenTarget * m_trials));
    ui->cumulativeFractionLabel->setText(QString("%1 / %2").arg(m_totalCorrectChars).arg(lenTarget * m_totalTrials));

    if (m_trials == ui->trialsSpinBox->value())
    {
        ui->startButton->show();
        ui->responseStrLineEdit->hide();
        ui->nextButton->hide();
        /* Enable settings */
        ui->settingsPane->setEnabled(true);
    }
    else
    {
        processTrial();
    }
}

void MainWindow::on_responseString_returnPressed()
{
    on_nextButton_clicked();    /* Pressing return has the same effect as clicking next */
}

void MainWindow::timerDisplayRandStr()
{
    ui->targetStrLineEdit->setText(QString(""));
    /* Enable the response line editor and next button */
    ui->responseStrLineEdit->setEnabled(true);
    ui->responseStrLineEdit->setFocus();
    ui->nextButton->setEnabled(true);
}

void MainWindow::processTrial()
{
    ui->responseStrLineEdit->setText("");
    ui->targetStrLineEdit->setText(m_randStr.generateString());
    ui->responseStrLineEdit->setEnabled(false);
    ui->nextButton->setEnabled(false);

    /* count the number of trials */
    m_trials++;
    m_totalTrials++;
    ui->nextButton->setText(QString("String %1").arg(m_trials));
    /* begin exposure */
    QTimer::singleShot(m_expInterval, this, SLOT(timerDisplayRandStr()));
}
