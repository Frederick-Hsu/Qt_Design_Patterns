#ifndef CAR_BUILDER_H
#define CAR_BUILDER_H

    #include "CarBuilderBase.h"

    class GMCarBuilder;
    class FordCarBuilder;
    class CarDirector;

    class GMCarBuilder : public CarBuilderBase
    {
    public:
    protected:
        void BuildManufactory() override;
        void BuildEngine() override;
        void BuildChassis() override;
        void BuildWheel() override;
    };

    class FordCarBuilder : public CarBuilderBase
    {
    protected:
        void BuildManufactory() override;
        void BuildEngine() override;
        void BuildChassis() override;
        void BuildWheel() override;
    };

    class CarDirector
    {
    public:
        Car* BuilderCar(CarBuilderBase* pBuilder);
    };

#endif  /* CAR_BUILDER_H */
