#include "QObjectTreeItem.h"

#include <QVariant>

QObjectTreeItem::QObjectTreeItem(QObject* object_in, QObjectTreeItem* parent)
{
    m_parentItem = parent;
    m_obj = object_in;
    if (m_obj)
    {
        const QMetaObject* metaobj = m_obj->metaObject();
        if (metaobj)
        {
            m_object_type = metaobj->className();
        }
        else
        {
            m_object_type = "Unknown";
        }
        QString text = m_obj->objectName();
        if (text.isEmpty())
            text = m_obj->property("title").toString();
        if (text.isEmpty())
            text = m_obj->property("windowTitle").toString();
        if (text.isEmpty())
            text = m_obj->property("text").toString();
        text = text.left(20);
        if (!text.isEmpty())
        {
            m_object_type += QString(" (%1)").arg(text);
        }
        connect(m_obj, SIGNAL(destroyed()), this, SLOT(on_object_destroyed()));
    }
    else
    {
        m_object_type = "Objects";
    }
}

QObjectTreeItem::~QObjectTreeItem()
{
    qDeleteAll(m_childItems);
    m_childItems.clear();
}

void QObjectTreeItem::appendChild(QObjectTreeItem *child)
{
    m_childItems.append(child);
}

void QObjectTreeItem::removeChild(int row)
{
    QObjectTreeItem* ptr = child(row);
    m_childItems.removeOne(ptr);
    if (ptr)
    {
        delete ptr;
    }
}

QObjectTreeItem* QObjectTreeItem::child(int row)
{
    return m_childItems.value(row);
}

int QObjectTreeItem::childCount() const
{
    return  m_childItems.count();
}

int QObjectTreeItem::columnCount() const
{
    return 1;
}

QVariant QObjectTreeItem::data(int column) const
{
    if (column == 0)
    {
        return QVariant(m_object_type);
    }
    else
    {
        return QVariant();
    }
}

int QObjectTreeItem::row() const
{
    if (m_parentItem)
    {
        return m_parentItem->m_childItems.indexOf(const_cast<QObjectTreeItem*>(this));
    }
    return 0;
}

QObjectTreeItem* QObjectTreeItem::parent()
{
    return m_parentItem;
}

QObjectTreeItem* QObjectTreeItem::find_child(QObject *ptr)
{
    for (int cnt = 0; cnt < m_childItems.count(); ++cnt)
    {
        if (child(cnt)->m_obj == ptr)
        {
            return child(cnt);
        }
    }
    return nullptr;
}

void QObjectTreeItem::on_object_destroyed()
{
    m_obj = nullptr;
}
