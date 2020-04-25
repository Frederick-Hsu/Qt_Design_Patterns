#include "QObjectTree.h"

#include <QMenu>
#include <QMouseEvent>

QObjectTree::QObjectTree()
{
    setup_widget_menu();
}

QObjectTree::~QObjectTree()
{
}

void QObjectTree::setup_widget_menu()
{
    widget_menu = new QMenu;
    QAction *act;

    /* Show */
    act = new QAction(tr("Show"), this);
    connect(act, SIGNAL(triggered()), this, SIGNAL(show_widget()));
    widget_menu->addAction(act);

    /* Hide */
    act = new QAction(tr("Hide"), this);
    connect(act, SIGNAL(triggered()), this, SIGNAL(hide_widget()));
    widget_menu->addAction(act);

    /* Focus */
    act = new QAction(tr("Focus"), this);
    connect(act, SIGNAL(triggered()), this, SIGNAL(focus_widget()));
    widget_menu->addAction(act);
}

void QObjectTree::currentChanged(const QModelIndex&, const QModelIndex&)
{
    emit current_item_changed();
}

void QObjectTree::mousePressEvent(QMouseEvent *event)
{
    QTreeView::mousePressEvent(event);
    if (event->button() == Qt::RightButton)
    {
        widget_menu->popup(mapToGlobal(QPoint(event->x(), event->y())));
    }
}
