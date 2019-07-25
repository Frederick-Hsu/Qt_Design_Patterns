#ifndef FILM_H
#define FILM_H

    #include <QString>
    #include <QDate>

    class Film
    {
    public:
        Film(QString id, QString title, QString dir, unsigned length, QDate relDate);
        virtual ~Film();
        Film(QStringList propList);
        virtual QString toString(bool labeled, QString sepchar);
    private:
        QString m_FilmID;
        QString m_Title;
        QString m_Director;
        unsigned m_FilmLength;
        QDate m_ReleaseDate;
    };

#endif  /* FILM_H */
