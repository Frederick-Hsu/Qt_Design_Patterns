#ifndef CARD_PICS_H
#define CARD_PICS_H

    #include <QObject>
    #include <QMap>
    #include <QString>
    #include <QImage>

    class CardPics : public QObject
    {
        Q_OBJECT
    public:
        explicit CardPics(QObject* parent = nullptr);
        ~CardPics();

        static CardPics* instance();

        static const QString values;
        static const QString suits;
        QImage get(QString card) const;
    protected:
        static QString fileName(QString card);
    private:
        QMap<QString, QImage> m_Images;
    };

#endif  /* CARD_PICS_H */
