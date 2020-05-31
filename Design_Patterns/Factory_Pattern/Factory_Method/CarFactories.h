#ifndef CAR_FACTORIES_H
#define CAR_FACTORIES_H

    #include "IFactory.h"

    class GMFactory;
    class FordFactory;
    class ToyotaFactory;

    class GMFactory : public IFactory
    {
    public:
        CarBase* Create() override;
    };

    class FordFactory : public IFactory
    {
    public:
        CarBase* Create() override;
    };

    class ToyotaFactory : public IFactory
    {
    public:
        CarBase* Create() override;
    };

    void FactoryMethodTest(void);

#endif  /* CAR_FACTORIES_H */
