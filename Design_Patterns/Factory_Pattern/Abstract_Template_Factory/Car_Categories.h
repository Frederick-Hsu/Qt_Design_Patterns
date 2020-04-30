#ifndef CAR_CATEGORIES_H
#define CAR_CATEGORIES_H

    #include "../Simple_Factory/CarBase.h"

    class BusinessCarBase;
    class SportCarBase;

    class BusinessCarBase : public CarBase
    {
    protected:
        BusinessCarBase() {}
        BusinessCarBase(const string& name);
    };

    class SportCarBase : public CarBase
    {
    protected:
        SportCarBase() {}
        SportCarBase(const string& name);
    };

/*================================================================================================*/

    class BMWBusinessCar;
    class BMWSportCar;
    class BenzBusinessCar;
    class BenzSportCar;

    class BMWBusinessCar : public BusinessCarBase
    {
    public:
        BMWBusinessCar();
        void PrintName();
    };

    class BMWSportCar : public SportCarBase
    {
    public:
        BMWSportCar();
        void PrintName();
    };

    class BenzBusinessCar : public BusinessCarBase
    {
    public:
        BenzBusinessCar();
        void PrintName();
    };

    class BenzSportCar : public SportCarBase
    {
    public:
        BenzSportCar();
        void PrintName();
    };

#endif  /* CAR_CATEGORIES_H */
