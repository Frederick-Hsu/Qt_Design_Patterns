#ifndef QOBJECTBROWSER_H
#define QOBJECTBROWSER_H

    #include "qobjectbrowser_global.h"
    #include "qobjecttree.h"

    #include <QSignalMapper>
    #include <QWidget>
    #include <QList>
    #include <QScopedPointer>

    class Ui_qobjectbrowser;
    class QCloseEvent;

    class QOB_signal_record
    /* A record that keeps count of how many times a signal was emitted */
    {
    public:
        QSignalMapper *m_sigmapper;
        long m_count;

        QOB_signal_record();
        virtual ~QOB_signal_record();
    };

    class QObjectBrowserControl : public QWidget
    /* A Designer widget - see qobjectbrowser.ui */
    {
        Q_OBJECT
    public:
        QList<QOB_signal_record *> m_signal_records;
        QObject* m_obj;

        explicit QObjectBrowserControl(QWidget* parent = nullptr);
        virtual ~QObjectBrowserControl();

        void clear_signal_records();
        void clear();
        void set_object(QObject* obj_in);
        void set_children();
        void set_properties();
        void set_signals();
        void update_signal_values();
        void update_signal_value(int sig_num);
        void set_slots();
        void set_methods();
        bool hasdescendent(QObject* m_obj);
    public slots:
        void on_signal_triggered(int signal_num);
        void on_update_children();
        void on_update_properties();
        void on_up_to_parent();
        void on_children_table_cell_clicked(int row, int column);
        void on_object_destroyed();
    signals:
        void object_changed(QObject* m_obj);
    private:
        Ui_qobjectbrowser* ui;
    };

    class QOBJECTBROWSERSHARED_EXPORT QObjectBrowser : public QWidget
    /* An object browser, traversing the tree of QObjects that is your application,
     * with maximal possible metadata details. A usefull runtime debugging tool.
     */
    {
        Q_OBJECT
    public:
        explicit QObjectBrowser(QWidget* parent = nullptr);

        void closeEvent(QCloseEvent*);
        void set_object(QObject* obj);
        bool valid_object(QObject* obj);
        QObject* get_current_object();
    public:
        QScopedPointer<QObjectBrowserControl> m_control;
        QScopedPointer<QObjectTree> m_tree;
        QObjectTreeModel m_model;
        QWidget* m_last_focus_window;
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
