#ifndef QOBJECTBROWSER_H
#define QOBJECTBROWSER_H

    #include "QObjectTreeModel.h"

    #include <QWidget>

    class QObjectBrowser;
    class QObjectBrowserControl;
    class QObjectTree;

    class QObjectBrowser : public QWidget
    {
        Q_OBJECT
    public:
        explicit QObjectBrowser(QWidget* parent = nullptr);
    public:
        QScopedPointer<QObjectBrowserControl> m_control;
        QScopedPointer<QObjectTree> m_tree;
        QObjectTreeModel m_model;
        QWidget* m_last_focus_window;
    public:
        void closeEvent(QCloseEvent*) override;
        void set_object(QObject* obj);
        bool valid_object(QObject* obj);
        QObject* get_current_object();
    public slots:
        void on_current_item_changed();
        void on_object_changed(QObject* obj);
        void on_update();
        void dumpObject();
        void on_focus_changed(QWidget* old, QWidget* now);
        void on_browse_focus();
        void on_show_widget();
        void on_hide_widget();
        void on_focus_widget();
    signals:
        void hidden();
    protected:
        void restoreSettings();
        void saveSettings();
    };

#endif  /* QOBJECTBROWSER_H */
