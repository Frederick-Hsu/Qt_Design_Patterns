#ifndef GRADSTUDENT_H
#define GRADSTUDENT_H

    #include "Student.h"

    class GradStudent : public Student
    {
    public:
        enum Support
        {
            TA,
            RA,
            FellowShip,
            Other
        };
        GradStudent(QString nm, long id, QString major, int yr, Support support);
        ~GradStudent();

        QString getClassName() const;
        QString toString() const;
    protected:
        static QString supportStr(Support sup);
    private:
        Support m_Support;
    };


#endif  /* GRADSTUDENT_H */
