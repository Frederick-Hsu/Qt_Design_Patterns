#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H

    class BusinessCarBase;
    class SportCarBase;

    class IAbstractFactory;
    class BMWFactory;
    class BenzFactory;

    class IAbstractFactory
    {
    public:
        virtual BusinessCarBase* CreateBusinessCar()    = 0;
        virtual SportCarBase*    CreateSportCar()       = 0;
    };

    class BMWFactory : public IAbstractFactory
    {
    public:
        BusinessCarBase* CreateBusinessCar()    override;
        SportCarBase*    CreateSportCar()       override;
    };

    class BenzFactory : public IAbstractFactory
    {
    public:
        BusinessCarBase* CreateBusinessCar()    override;
        SportCarBase*    CreateSportCar()       override;
    };

    void AbstractFactoryTest(void);

#endif  /* ABSTRACT_FACTORY_H */
