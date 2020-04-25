#ifndef QOBJECTBROWSERACTION_H
#define QOBJECTBROWSERACTION_H

    #include <QAction>
    #include <QScopedPointer>

    class QObjectBrowserAction;
    class QObjectBrowser;

    class QObjectBrowserAction : public QAction
    {
        Q_OBJECT
    public:
        QObjectBrowserAction(QObject* parent = nullptr);
    private:
        QScopedPointer<QObjectBrowser> m_browser;
    public:
        bool isChecked() const;
    public slots:
        void setChecked(bool);
        void checkCheck();
    };

#endif  /* QOBJECTBROWSERACTION_H */
