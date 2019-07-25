#ifndef FILMLIST_H
#define FILMLIST_H

    #include "Film.h"
    #include <QList>
    #include <QString>

    class FilmList : public QList<Film*>
    {
    public:
        QString toString();
        Film* findFilm(QString id);
        QString getID(QString title);
        void addFilm(Film* film);
        void removeFilm(QString filmID);
    };

#endif  /* FILMLIST_H */
