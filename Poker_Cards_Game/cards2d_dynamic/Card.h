#ifndef CARD_H
#define CARD_H

    #include "cards2d_global.h"

    #include <QObject>
    #include <QLabel>
    #include <QPixmap>
    #include <QString>

    class CARDS2DSHARED_EXPORT Card : public QLabel
    {
        Q_OBJECT
    public:
        Card(QString name, QWidget* parent = nullptr);
        int value();
        bool isAce() const;
    private:
        QPixmap m_pixmap;
    };

#endif  /* CARD_H */
