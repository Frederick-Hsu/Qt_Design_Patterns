#ifndef CARD_H
#define CARD_H

    #include <QObject>
    #include <QLabel>
    #include <QPixmap>
    #include <QString>

    class Card : public QLabel
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
