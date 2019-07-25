#ifndef EDUCATIONAL_H
#define EDUCATIONAL_H

    #include <QString>
    #include "Entertainment.h"
    #include "Film.h"

    class Educational : public Film
    {
    private:
        QString m_Subject;
        Entertainment::MPAARatings m_GradLevel;
    public:
        Educational(QString title,
                    QString dir,
                    unsigned len,
                    QDate relDate,
                    QString subject,
                    Entertainment::MPAARatings grade);
        Educational(QStringList propList);
        QString toString(bool labeled, QString sepchar);
    };

#endif  /* EDUCATIONAL_H */
