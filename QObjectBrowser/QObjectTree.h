#ifndef QOBJECTTREE_H
#define QOBJECTTREE_H

    #include <QTreeView>

    class QObjectTree;

    class QObjectTree : public QTreeView
    {
        Q_OBJECT
    public:
        QMenu* widget_menu;
    public:
        QObjectTree();
        virtual ~QObjectTree() override;
    public:
        void setup_widget_menu();
    protected:
        void currentChanged(const QModelIndex& current, const QModelIndex& previous) override;
        void mousePressEvent(QMouseEvent* event) override;
    signals:
        void current_item_changed();
        void show_widget();
        void hide_widget();
        void focus_widget();
    };

#endif  /* QOBJECTTREE_H */
