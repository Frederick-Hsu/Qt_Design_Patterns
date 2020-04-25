#include "QObjectBrowser.h"
#include "QObjectBrowserControl.h"
#include "QObjectTree.h"

#include <QVBoxLayout>
#include <QToolBar>
#include <QSplitter>
#include <QPushButton>
#include <QCoreApplication>
#include <QTimer>
#include <QSettings>
#include <QRect>

QObjectBrowser::QObjectBrowser(QWidget* parent) : QWidget(parent),
                                                  m_control(new QObjectBrowserControl),
                                                  m_tree(new QObjectTree)
{
    m_last_focus_window = nullptr;
    setObjectName(QString::fromUtf8("QObjectBrowser"));
    setWindowTitle(tr("QObject Browser utility"));
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint);

    m_tree->setModel(&m_model);
    QVBoxLayout* layout = new QVBoxLayout(this);
    setLayout(layout);

    QToolBar* update_toolbar = new QToolBar(tr("Update"));
    layout->addWidget(update_toolbar);

    QSplitter *spliter = new QSplitter(Qt::Horizontal, this);
    layout->addWidget(spliter);
    spliter->addWidget(m_tree.data());
    spliter->addWidget(m_control.data());
    spliter->setStretchFactor(0, 1);
    spliter->setStretchFactor(1, 0);

    m_tree->update();

    QPushButton* updateButton = new QPushButton(QString("Update"), this);
    update_toolbar->addWidget(updateButton);
    connect(updateButton, SIGNAL(clicked), this, SLOT(on_update()));

    QPushButton* dumpButton = new QPushButton(QString("Dump Object"), this);
    update_toolbar->addWidget(dumpButton);
    connect(dumpButton, SIGNAL(clicked()), this, SLOT(dumpObject()));

    QPushButton* focusButton = new QPushButton(QString(tr("Browse Focus Widget")), this);
    update_toolbar->addWidget(focusButton);
    connect(focusButton, SIGNAL(clicked()), this, SLOT(on_browse_focus()));

    connect(m_tree.data(), SIGNAL(show_widget()), this, SLOT(on_show_widget()));
    connect(m_tree.data(), SIGNAL(hide_widget()), this, SLOT(on_hide_widget()));
    connect(m_tree.data(), SIGNAL(focus_widget()), this, SLOT(on_focus_widget()));
    connect(m_tree.data(), SIGNAL(object_changed()), this, SLOT(on_current_item_changed()));
    connect(qApp, SIGNAL(focusChanged(QWidget*, QWidget*)), this, SLOT(on_focus_changed(QWidget*, QWidget*)));

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(on_update()));
    // connect(timer, SIGNAL(timeout()), this, SLOT(on_current_time_changed()));
    timer->start(3000);

    restoreSettings();
}

void QObjectBrowser::closeEvent(QCloseEvent *event)
{
    saveSettings();
    emit hidden();
    QWidget::closeEvent(event);
}

void QObjectBrowser::saveSettings()
{
    QSettings settings;
    settings.setValue("obrowser/geometry", geometry());
}

void QObjectBrowser::restoreSettings()
{
    QSettings settings;
    setGeometry(settings.value("obrowser/geometry", geometry()).toRect());
}

void QObjectBrowser::set_object(QObject *obj)
{
    if (m_model.find_item(m_model.rootItem, obj))
    {
        m_control->set_object(obj);
    }
    else
    {
        m_control->set_object(nullptr);
    }
}
