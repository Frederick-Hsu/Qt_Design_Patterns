#include "QObjectBrowserAction.h"
#include "QObjectBrowser.h"

#include <QCoreApplication>

QObjectBrowserAction::QObjectBrowserAction(QObject* parent) : QAction(tr("Object Browser"), parent),
                                                              m_browser(nullptr)
{
    setObjectName(tr("objectBrowserAction"));
    setChecked(true);
    connect(this, SIGNAL(triggered(bool)), this, SLOT(setChecked(bool)));
    if (parent == nullptr)
    {
        connect(qApp, SIGNAL(aboutToQuit()), this, SLOT(deleteLater()));
    }
}

bool QObjectBrowserAction::isChecked() const
{
    if (m_browser.isNull())
        return false;
    return m_browser->isVisible();
}

void QObjectBrowserAction::setChecked(bool checked)
{
    QAction::setChecked(checked);
    if (checked && m_browser.isNull())
    {
        m_browser.reset(new QObjectBrowser);
        connect(m_browser.data(), SIGNAL(hidden()), this, SLOT(checkCheck()));
    }
    m_browser->setVisible(checked);
}

void QObjectBrowserAction::checkCheck()
{
    setChecked(false);
}
