#ifndef QOBJECTTREEITEM_H
#define QOBJECTTREEITEM_H

    #include <QObject>
    #include <QList>
    #include <QVariant>

    class QObjectTreeItem;

    class QObjectTreeItem : public QObject
    {
        Q_OBJECT
    public:
        QObject* m_obj;
    public:
        QObjectTreeItem(QObject* object_in, QObjectTreeItem* parent = nullptr);
        ~QObjectTreeItem();
    public:
        void appendChild(QObjectTreeItem* child);
        void removeChild(int row);
        QObjectTreeItem* child(int row);
        int childCount() const;
        int columnCount() const;
        QVariant data(int column) const;
        int row() const;
        QObjectTreeItem* parent();
        QObjectTreeItem* find_child(QObject* ptr);
    public slots:
        void on_object_destroyed();
    private:
        QList<QObjectTreeItem*> m_childItems;
        QString m_object_type;
        QObjectTreeItem* m_parentItem;
    };

#endif  /* QOBJECTTREEITEM_H */
