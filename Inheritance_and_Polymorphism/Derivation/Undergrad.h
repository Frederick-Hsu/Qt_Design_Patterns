#ifndef UNDERGRAD_H
#define UNDERGRAD_H

    #include "Student.h"

    class Undergrad : public Student
    {
    public:
        Undergrad(QString name, long id, QString major, int year, int sat);
        ~Undergrad();

        QString getClassName() const;
        QString toString() const;
    private:
        int m_SAT;      /* Scholastic Aptitude Test score total. */
    };

#endif  /* UNDERGRAD_H */
