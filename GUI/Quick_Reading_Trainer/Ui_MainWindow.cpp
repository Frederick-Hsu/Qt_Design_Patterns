#include "Ui_MainWindow.h"

#include <QMainWindow>
#include <QGridLayout>
#include <QApplication>

void Ui_MainWindow::setupUi(QMainWindow *mainwindow)
{
    if (mainwindow->objectName().isEmpty())
        mainwindow->setObjectName(QString::fromUtf8("mainwindow"));
    mainwindow->resize(2400, 500);
    mainwindow->setWindowTitle(QString("Quick Reading Trainer"));

    QWidget *centralWidget = new QWidget(mainwindow);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    mainwindow->setCentralWidget(centralWidget);

    QGroupBox *settingsPane = new QGroupBox(mainwindow);
    settingsPane->setObjectName(QString::fromUtf8("rightPane"));
    settingsPane->setTitle(QString("Settings"));
    settingsPane->setAlignment(Qt::AlignCenter);

    QLabel *numTrialsLabel = new QLabel(QString("Number of trials"));
    numTrialsLabel->setObjectName(QString::fromUtf8("numTrialsLabel"));
    trialsSpinBox = new QSpinBox();
    trialsSpinBox->setObjectName(QString::fromUtf8("trialsSpinBox"));
    trialsSpinBox->setMinimum(1);
    trialsSpinBox->setValue(5);

    QLabel *exposureLabel = new QLabel(QString("Exposure"));
    exposureLabel->setObjectName(QString::fromUtf8("exposureLabel"));
    exposureSlider = new QSlider(Qt::Horizontal);
    exposureSlider->setObjectName(QString::fromUtf8("exposureSlider"));
    exposureSlider->setMinimum(100);
    exposureSlider->setMaximum(3000);
    exposureSlider->setSingleStep(10);
    exposureSlider->setValue(700);
    QLabel *msecLabel = new QLabel(QString("msec"));
    msecLabel->setObjectName(QString::fromUtf8("msecLabel"));

    exposureLCD = new QLCDNumber();
    exposureLCD->setObjectName(QString::fromUtf8("exposureLCD"));
    exposureLCD->setMode(QLCDNumber::Dec);
    // exposureLCD->setMode(QLCDNumber::Hex);

    QLabel *lengthLabel = new QLabel(QString("Length"));
    lengthLabel->setObjectName(QString::fromUtf8("lengthLabel"));
    lengthSlider = new QSlider(Qt::Horizontal);
    lengthSlider->setObjectName(QString::fromUtf8("lengthSlider"));
    lengthSlider->setMinimum(5);
    lengthSlider->setMaximum(50);
    lengthSlider->setValue(15);

    lengthLCD = new QLCDNumber();
    lengthLCD->setObjectName(QString::fromUtf8("lengthLCD"));
    lengthLCD->setMode(QLCDNumber::Dec);
    QLabel *charLabel = new QLabel(QString("char"));
    charLabel->setObjectName(QString::fromUtf8("charLabel"));

    QGridLayout* widgetsGridLayout = new QGridLayout();
    widgetsGridLayout->addWidget(numTrialsLabel, 0, 0, 1, 1);
    widgetsGridLayout->addWidget(trialsSpinBox, 0, 1, 1, 5);

    widgetsGridLayout->addWidget(exposureLabel, 1, 0, 1, 1);
    widgetsGridLayout->addWidget(exposureSlider, 1, 1, 1, 4);
    widgetsGridLayout->addWidget(exposureLCD, 1, 5, 1, 1);
    widgetsGridLayout->addWidget(msecLabel, 1, 6, 1, 1);

    widgetsGridLayout->addWidget(lengthLabel, 2, 0, 1, 1);
    widgetsGridLayout->addWidget(lengthSlider, 2, 1, 1, 4);
    widgetsGridLayout->addWidget(lengthLCD, 2, 5, 1, 1);
    widgetsGridLayout->addWidget(charLabel, 2, 6, 1, 1);
    settingsPane->setLayout(widgetsGridLayout);

#if 1
    QGroupBox *summaryGroupBox = new QGroupBox(QString("Summary"), mainwindow);
    summaryGroupBox->setObjectName(QString::fromUtf8("summaryGroupBox"));
    summaryGroupBox->setAlignment(Qt::AlignCenter);

    QLabel* correctCharsLabel = new QLabel(QString("Characters correct: "));
    correctCharsLabel->setObjectName(QString::fromUtf8("correctCharsLabel"));
    QLabel* totalCorrectCharsLabel = new QLabel(QString("Total chars correct: "));
    totalCorrectCharsLabel->setObjectName(QString::fromUtf8("totalCorrectCharsLabel"));
    correctCharFractionLabel = new QLabel(QString(" / "));
    correctCharFractionLabel->setObjectName(QString::fromUtf8("correctCharFractionLabel"));
    cumulativeFractionLabel = new QLabel(QString(" / "));
    cumulativeFractionLabel->setObjectName(QString::fromUtf8("cumulativeFractionLabel"));

    QGridLayout* scorePanelGridLayout = new QGridLayout();
    scorePanelGridLayout->addWidget(correctCharsLabel, 0, 0, 1, 2);
    scorePanelGridLayout->addWidget(correctCharFractionLabel, 0, 3, 1, 2);
    scorePanelGridLayout->addWidget(totalCorrectCharsLabel, 1, 0, 1, 2);
    scorePanelGridLayout->addWidget(cumulativeFractionLabel, 1, 3, 1, 2);
    summaryGroupBox->setLayout(scorePanelGridLayout);

    QVBoxLayout* vlayout = new QVBoxLayout();
    vlayout->addWidget(settingsPane);
    vlayout->addSpacing(1);
    vlayout->addWidget(summaryGroupBox);
#endif

    QGroupBox* leftPane = new QGroupBox(QString("Speed Reader"), mainwindow);
    leftPane->setObjectName(QString::fromUtf8("leftPane"));
    leftPane->setAlignment(Qt::AlignCenter);

    targetStrLabel = new QLabel(QString("Target String"), leftPane);
    targetStrLabel->setObjectName(QString::fromUtf8("targetStrLabel"));
    targetStrLineEdit = new QLineEdit(leftPane);
    targetStrLineEdit->setObjectName(QString::fromUtf8("targetStrLineEdit"));
    targetStrLineEdit->setEnabled(true);
    targetStrLineEdit->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    targetStrLineEdit->setText(QString("Get ready to watch this space"));

    respStrLabel = new QLabel(QString("Response String"), leftPane);
    respStrLabel->setObjectName(QString::fromUtf8("respStrLabel"));
    responseStrLineEdit = new QLineEdit(QString("Type target string here"), leftPane);
    responseStrLineEdit->setObjectName(QString::fromUtf8("responseStrLineEdit"));

    startButton = new QPushButton(QString("Start"), leftPane);
    startButton->setObjectName(QString::fromUtf8("startButton"));
    nextButton = new QPushButton(QString("Next"), leftPane);
    nextButton->setObjectName(QString::fromUtf8("nextButton"));

    QVBoxLayout* vlayoutInLeftPane = new QVBoxLayout();
    vlayoutInLeftPane->addWidget(targetStrLabel);
    vlayoutInLeftPane->addWidget(targetStrLineEdit);
    vlayoutInLeftPane->addStrut(2);
    vlayoutInLeftPane->addWidget(respStrLabel);
    vlayoutInLeftPane->addWidget(responseStrLineEdit);
    vlayoutInLeftPane->addStretch(4);
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(startButton);
    buttonsLayout->addSpacing(200);
    buttonsLayout->addWidget(nextButton);
    vlayoutInLeftPane->addLayout(buttonsLayout);
    vlayoutInLeftPane->addStretch(1);
    leftPane->setLayout(vlayoutInLeftPane);

    QHBoxLayout* windowLayout = new QHBoxLayout();
    windowLayout->addWidget(leftPane, 1);
    windowLayout->addSpacing(1);
    windowLayout->addLayout(vlayout, 1);
    centralWidget->setLayout(windowLayout);
    QMetaObject::connectSlotsByName(mainwindow);
}

void Ui_MainWindow::retranslateUi(QMainWindow *mainwindow)
{
    mainwindow->setWindowTitle(QApplication::translate("mainwindow", "Quick Reading Trainer", nullptr));
    /* empty, keep it simple */
}
