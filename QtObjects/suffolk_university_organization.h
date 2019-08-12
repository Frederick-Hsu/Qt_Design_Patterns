#ifndef SUFFOLK_UNIVERSITY_ORGANIZATION_H
#define SUFFOLK_UNIVERSITY_ORGANIZATION_H

    #include <QObject>

    class OrgUnit : public QObject
    {
    public:
        QString getName();
        double getSalary();
    private:
        QString m_Name;
        double m_Salary;
    };

    class Person : public QObject
    {
    public:
        explicit Person(QString name, QObject* parent = 0);
        virtual ~Person();
    };

    void growBunch();
    void showTree(QObject* theparent);


#endif  /* SUFFOLK_UNIVERSITY_ORGANIZATION_H */
