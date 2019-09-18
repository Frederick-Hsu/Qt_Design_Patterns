#ifndef QOBJECTBROWSERACTION_H
#define QOBJECTBROWSERACTION_H

    #include "qobjectbrowser_global.h"
    #include "qobjectbrowser.h"

    #include <QAction>
    #include <QScopedPointer>

    class QOBJECTBROWSERSHARED_EXPORT QObjectBrowserAction : public QAction
    {
        Q_OBJECT
    public:
        QObjectBrowserAction(QObject* parent = nullptr);
        bool isChecked() const;
    public slots:
        void setChecked(bool);
        void checkCheck();
    private:
        QScopedPointer<QObjectBrowser> m_browser;
    };

#endif  /* QOBJECTBROWSERACTION_H */
