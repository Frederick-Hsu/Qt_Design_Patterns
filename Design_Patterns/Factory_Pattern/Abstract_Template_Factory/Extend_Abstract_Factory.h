#ifndef EXTEND_ABSTRACT_FACTORY_H
#define EXTEND_ABSTRACT_FACTORY_H

    #include "../Simple_Factory/CarBase.h"
    #include "Abstract_Factory.h"

    class TruckCarBase;
    class IExtendedAbstractFactory;

    class TruckCarBase : public CarBase
    {
    public:
        TruckCarBase() {}
        TruckCarBase(const string& name) : CarBase(name) {}
    };

    class IExtendedAbstractFactory : public IAbstractFactory
    {
    public:
        virtual TruckCarBase* CreateTruckCar() = 0;
    };

/*================================================================================================*/

    class BMWTruckCar;
    class BenzTruckCar;

    class BMWTruckCar : public TruckCarBase
    {
    public:
        BMWTruckCar() : TruckCarBase("BMW truck car") {}
        void PrintName();
    };

    class BenzTruckCar : public TruckCarBase
    {
    public:
        BenzTruckCar() : TruckCarBase("Benz truck car") {}
        void PrintName();
    };

    class BenzExtendedFactory;
    class BMWExtendedFactory;

    class BenzExtendedFactory : public IExtendedAbstractFactory
    {
    public:
        BusinessCarBase* CreateBusinessCar() override;
        SportCarBase* CreateSportCar() override;
        TruckCarBase* CreateTruckCar() override;
    protected:
        BenzFactory factory;
    };

    class BMWExtendedFactory : public IExtendedAbstractFactory
    {
    public:
        BusinessCarBase* CreateBusinessCar() override;
        SportCarBase* CreateSportCar() override;
        TruckCarBase* CreateTruckCar() override;
    protected:
        BMWFactory factory;
    };

    void ExtendedAbstractFactoryTest(void);

#endif  /* EXTEND_ABSTRACT_FACTORY_H */
