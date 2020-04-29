#ifndef CAR_FACTORY_H
#define CAR_FACTORY_H

    #include <string>
    using namespace std;

    class CarBase;
    class CarFactory;

    class CarFactory
    {
    public:
        static CarBase* Create(const string& name);     /* Static Factory Method */
    };

#endif  /* CAR_FACTORY_H */
