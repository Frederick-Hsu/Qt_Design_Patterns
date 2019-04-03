#ifndef STUDENT_H
#define STUDENT_H

    #include <QString>

    // #define DEBUG_INDICATOR

    class Student
    {
    public:
        Student(QString nm, long id, QString major, int year = 1);
        virtual ~Student();

        virtual QString getClassName() const;
        virtual QString toString() const;
    private:
        QString m_Name;
        QString m_Major;
        long m_StudentId;
    protected:
        int m_Year;
        QString yearStr() const;
    };

#endif  /* STUDENT_H */
