#ifndef PERSON_H
#define PERSON_H

    #include <string>
    #include "Position.h"
    #include "Employer.h"

    class Person
    {
    public:
        Person(std::string name);
        std::string toString();
        void setPosition(Employer empl, Position pos);
        Position getPositon();
        Employer getEmployer();
    private:
        std::string m_Name;
        bool m_Emplyed;
        Position m_Position;
        Employer m_Employer;
    };

#endif  /* PERSON_H */
