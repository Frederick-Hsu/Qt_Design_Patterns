#include "QObjectTreeModel.h"
#include "QObjectTreeItem.h"

#include <QIcon>
#include <QList>
#include <QPersistentModelIndex>
#include <QCoreApplication>
#include <QWidgetList>
#include <QWidget>
#include <QObjectList>

QList<QObject*> QObjectTreeModel::sm_extraObjects;

void QObjectTreeModel::addExtraObjects(QObject* extra)
{
    // sm_extraObjects << extra;
    sm_extraObjects.append(extra);      /* The 2 expressions are identical */
}

QObjectTreeModel::QObjectTreeModel(QObject* parent) : QAbstractItemModel(parent)
{
    rootItem = new QObjectTreeItem(nullptr);
    refresh();
}

QObjectTreeModel::~QObjectTreeModel()
{
    delete rootItem;
}

QVariant QObjectTreeModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }
    if (role == Qt::DisplayRole)
    {
        QObjectTreeItem* item = static_cast<QObjectTreeItem*>(index.internalPointer());
        if (item)
        {
            return item->data(index.column());
        }
    }
    else if (role == Qt::DecorationRole)
    {
        QObjectTreeItem* item = static_cast<QObjectTreeItem*>(index.internalPointer());
        if (item)
        {
            if (item->m_obj->isWidgetType())
            {
                return QIcon(":/images/widget.png");
            }
            else
            {
                return QIcon(":/image/object.png");
            }
        }
    }
    return QVariant();
}

Qt::ItemFlags QObjectTreeModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
    {
        return Qt::ItemIsEnabled;
    }
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant QObjectTreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        return rootItem->data(section);
    }
    return QVariant();
}

QModelIndex QObjectTreeModel::index(int row, int column, const QModelIndex& parent) const
{
    QObjectTreeItem* parentItem;
    if (!parent.isValid())
    {
        parentItem = rootItem;
    }
    else
    {
        parentItem = static_cast<QObjectTreeItem*>(parent.internalPointer());
    }
    QObjectTreeItem* childItem = parentItem->child(row);
    if (childItem)
    {
        return createIndex(row, column, childItem);
    }
    else
    {
        return QModelIndex();
    }
}

QModelIndex QObjectTreeModel::parent(const QModelIndex& index) const
{
    if (!index.isValid())
    {
        return QModelIndex();
    }
    QObjectTreeItem* childItem = static_cast<QObjectTreeItem*>(index.internalPointer());
    QObjectTreeItem* parentItem = childItem->parent();
    if (parentItem == rootItem)
    {
        return QModelIndex();
    }
    return createIndex(parentItem->row(), 0, parentItem);
}

int QObjectTreeModel::rowCount(const QModelIndex& parent) const
{
    QObjectTreeItem* parentItem;
    if (!parent.isValid())
    {
        parentItem = rootItem;
    }
    else
    {
        parentItem = static_cast<QObjectTreeItem*>(parent.internalPointer());
    }
    return parentItem->childCount();
}

int QObjectTreeModel::columnCount(const QModelIndex& parent) const
{
    if (parent.isValid())
    {
        return static_cast<QObjectTreeItem*>(parent.internalPointer())->columnCount();
    }
    else
    {
        return rootItem->columnCount();
    }
}

void QObjectTreeModel::refresh()
{
    layoutAboutToBeChanged(QList<QPersistentModelIndex>(), QAbstractItemModel::NoLayoutChangeHint);
    refresh(QModelIndex());
    /* emit the signal: layoutChanged */
    layoutChanged(QList<QPersistentModelIndex>(), QAbstractItemModel::NoLayoutChangeHint);
}

void QObjectTreeModel::clear_persistent_data(QModelIndex index)
{
    for (int cnt = 0; cnt < rowCount(index); ++cnt)
    {
        clear_persistent_data(index.child(cnt, 0));
    }
    changePersistentIndex(index, QModelIndex());
}

void QObjectTreeModel::refresh(const QModelIndex& aIndex)
{
    QModelIndex index = aIndex;
    QObjectTreeItem* parent = static_cast<QObjectTreeItem*>(index.internalPointer());
    if (!parent)
    {
        parent = rootItem;
        index = createIndex(0, 0, rootItem);
    }
    if (!parent)            return;
    if (!index.isValid())   return;

    QObjectList obj_list;
    if (parent->m_obj)
    {
        obj_list = parent->children();
    }
    else
    {
        obj_list.append(qApp);
        obj_list.append(sm_extraObjects);
        QWidgetList widgets;
        QObjectList children = qApp->children();
        for (QObjectList::iterator it = children.begin(); it != children.end(); ++it)
        {
            widgets.append(reinterpret_cast<QWidget*>(*it));
        }
        for (int cnt = 0; cnt < widgets.count(); ++cnt)
        {
            if (!widgets[cnt]->parentWidget())
            {
                obj_list.append(widgets[cnt]);
            }
        }
    }
    for (int idx = 0; idx < obj_list.count(); ++idx)
    {
        QObjectTreeItem* child = parent->find_child(obj_list[idx]);
        if (!child)
        {
            child = new QObjectTreeItem(obj_list[idx]->parent());
            parent->appendChild(child);
        }
        else
        {
            refresh(index.child(child->row(), 0));
        }
    }
    for (int idx = 0; idx < parent->childCount(); ++idx)
    {
        if (!obj_list.contains(parent->child(idx)->m_obj))
        {
            clear_persistent_data(index.child(idx, 0));
            parent->removeChild(idx);
            idx--;
        }
    }
}

QModelIndex QObjectTreeModel::getIndex(QObject *obj)
{
    QObjectTreeItem* item = find_item(rootItem, obj);
    if (!item)
    {
        return QModelIndex();
    }
    return createIndex(item->row(), 0, item);
}

QObjectTreeItem* QObjectTreeModel::find_item(QObjectTreeItem *ptr, QObject *obj)
{
    if (!ptr)
        return nullptr;
    if (ptr->m_obj == obj)
    {
        return ptr;
    }
    for (int cnt = 0; cnt < ptr->childCount(); ++cnt)
    {
        QObjectTreeItem* ret = find_item(ptr->child(cnt), obj);
        if (ret)
        {
            return ret;
        }
    }

}
