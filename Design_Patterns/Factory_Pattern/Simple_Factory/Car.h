#ifndef CAR_H
#define CAR_H

    #include "CarBase.h"

    class GMCar;
    class FordCar;
    class ToyotaCar;

    class GMCar : public CarBase
    {
    public:
        GMCar();
        void PrintName() override;
    };

    class FordCar : public CarBase
    {
    public:
        FordCar();
        void PrintName() override;
    };

    class ToyotaCar : public CarBase
    {
    public:
        ToyotaCar();
        void PrintName() override;
    };

#endif  /* CAR_H */
