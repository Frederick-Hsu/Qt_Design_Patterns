#ifndef CARbASE_H
#define CARbASE_H

    #include <string>
    using namespace std;

    class CarBase;

    class CarBase
    {
    public:
        virtual ~CarBase();
        virtual void PrintName();
    protected:
        CarBase();
        CarBase(const string& name);
    protected:
        string m_manufacturerName;
    };

#endif  /* CARbASE_H */
