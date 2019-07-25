#ifndef ENTERTAINMENT_H
#define ENTERTAINMENT_H

    #include <QString>
    #include <QDate>

    #include "Film.h"

    class Entertainment : public Film
    {
    public:
        enum FilmTypes
        {
            Action,
            Comedy,
            SciFic,
        };
        enum MPAARatings
        {
            G,
            PG,
            PG_13
        };

        Entertainment(QString title,
                      QString dir,
                      unsigned len,
                      QDate relDate,
                      FilmTypes type,
                      MPAARatings rtng);
        Entertainment(QStringList propList);
        QString toString(bool labeled, QString sepchar);
    private:
        FilmTypes m_Type;
        MPAARatings m_Rating;
    };

#endif  /* ENTERTAINMENT_H */
