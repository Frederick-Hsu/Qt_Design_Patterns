#ifndef CAR_H
#define CAR_H

    #include <string>
    using namespace std;

    class Car;

    class Car
    {
    public:
        /* Manufactory y */
        void SetManufactory(const string& manufactory);
        const string& GetManufactory() const;

        void SetEngine(const string& engine);
        const string& GetEngine() const;

        void SetChassis(const string& chassis);
        const string& GetChassis() const;

        void SetWheel(const string& wheel);
        const string& GetWheel() const;

        void PrintInfo();
    protected:
        string m_strManufactory;
        string m_strEngine;
        string m_strChassis;
        string m_strWheel;
    };

#endif  /* CAR_H */
