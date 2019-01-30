#ifndef EMPLOYER_H
#define EMPLOYER_H

    #include <string>

    class Person;
    class Position;

    class Employer
    {
    public:
        Employer(std::string name, std::string market);
        Employer(const Employer& other);
        Employer& operator=(const Employer& other);
        bool hire(Person& newHire, Position pos);
        std::string toString();
    private:
        std::string m_Name;
        std::string m_Market;
    };

#endif  /* EMPLOYER_H */
