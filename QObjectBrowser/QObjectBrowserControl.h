#ifndef QOBJECTBROWSERCONTROL_H
#define QOBJECTBROWSERCONTROL_H

    #include <QWidget>
    #include <QList>
    #include <QScopedPointer>

    class QObjectBrowserControl;
    class QOB_signal_record;
    class Ui_QObjectBrowser;

    class QObjectBrowserControl : public QWidget
    {
        Q_OBJECT
    public:
        QList<QOB_signal_record*> m_signal_records;
        QObject* m_obj;
    public:
        explicit QObjectBrowserControl(QWidget* parent = nullptr);
        virtual ~QObjectBrowserControl();
    private:
        Ui_QObjectBrowser* ui;
    public:
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
        bool has_descendent(QObject* obj);
    public slots:
        void on_signal_triggered(int signal_num);
        void on_update_children();
        void on_update_properties();
        void on_up_to_parent();
        void on_children_table_cell_clicked(int row, int column);
        void on_object_destroyed();
    signals:
        void object_changed();
    };

#endif  /* QOBJECTBROWSERCONTROL_H */
