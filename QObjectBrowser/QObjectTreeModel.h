#ifndef QOBJECTTREEMODEL_H
#define QOBJECTTREEMODEL_H

    #include <QAbstractItemModel>
    #include <QList>
    #include <QVariant>
    #include <QModelIndex>

    class QObjectTreeModel;
    class QObjectTreeItem;

    class QObjectTreeModel : public QAbstractItemModel
    {
        Q_OBJECT
    public:
        QObjectTreeModel(QObject* parent = nullptr);
        ~QObjectTreeModel() override;
    public:
        QObjectTreeItem* rootItem;
        static QList<QObject*> sm_extraObjects;
    public:
        QVariant data(const QModelIndex& index, int role) const override;
        Qt::ItemFlags flags(const QModelIndex& index) const override;
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
        QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const override;
        QModelIndex parent(const QModelIndex& index) const override;
        int rowCount(const QModelIndex& parent = QModelIndex()) const override;
        int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    public:
        void refresh();
        void clear_persistent_data(QModelIndex index);
        void refresh(const QModelIndex& aIndex);
        QModelIndex getIndex(QObject* obj);
        QObjectTreeItem* find_item(QObjectTreeItem* ptr, QObject* obj);
        static void addExtraObjects(QObject* extra);
    };

#endif  /* QOBJECTTREEMODEL_H */
