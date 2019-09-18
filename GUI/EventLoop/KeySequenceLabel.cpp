#include "KeySequenceLabel.h"

#include <QCoreApplication>
#include <QEvent>
#include <QKeyEvent>
#include <QTimerEvent>
#include <QKeySequence>
#include <QPaintEvent>
#include <QStatusBar>
#include <QObjectBrowserAction>

KeySequenceLabel::KeySequenceLabel(QWidget* parent) : QMainWindow(parent),
                                                      m_browserAction(new QObjectBrowserAction(this))
{
    setupUi(this);
    startTimer(2000);
    m_paints = 0;
}

void KeySequenceLabel::keyPressEvent(QKeyEvent *evt)
{
    bool doNothing = false;
    if (evt->key() == 0)
        doNothing = true;
    if (m_keys.size() > 3)
        doNothing = true;
    if (doNothing)
    {
        QMainWindow::keyPressEvent(evt);
        return;
    }
    QPair<int, int> pair = QPair<int, int>(static_cast<int>(evt->modifiers()), evt->key());
    m_keys << pair;
    evt->accept();
    updateUi();
}

void KeySequenceLabel::updateUi()
{
    if (!m_keys.isEmpty())
    {
        int keys[4] = {0, 0, 0, 0};
        for (int index = 0; index < m_keys.size(); ++index)
        {
            QPair<int, int> pair = m_keys[index];
            keys[index] = pair.first | pair.second;
        }
        QKeySequence seq = QKeySequence(keys[0], keys[1], keys[2], keys[3]);
        dispLabel->setText(seq.toString());
    }
    else
    {
        dispLabel->clear();
    }
}

void KeySequenceLabel::enterEvent(QEvent *evt)
{
    statusBar()->showMessage(tr("Mouse is in a house"));
    evt->accept();
}

void KeySequenceLabel::leaveEvent(QEvent *evt)
{
    statusBar()->showMessage(tr("Mouse has left the building"));
    evt->accept();
}

void KeySequenceLabel::timerEvent(QTimerEvent*)
{
    ledDigits->display(m_paints);
}

void KeySequenceLabel::paintEvent(QPaintEvent *evt)
{
    ++m_paints;
    QMainWindow::paintEvent(evt);
}

void KeySequenceLabel::changeEvent(QEvent *evt)
{
    QMainWindow::changeEvent(evt);
    switch (evt->type())
    {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}

void KeySequenceLabel::on_quitAction_triggered()
{
    qApp->quit();
}

void KeySequenceLabel::on_clearBtn_clicked()
{
    m_keys.clear();
    updateUi();
}

void KeySequenceLabel::on_showObjectBrowser_triggered(bool checked)
{
    m_browserAction->setChecked(checked);
}
