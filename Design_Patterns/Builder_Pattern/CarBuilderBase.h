#ifndef CAR_BUILDER_BASE_H
#define CAR_BUILDER_BASE_H

    #include "Car.h"

    class CarBuilderBase;

    class CarBuilderBase
    {
    protected:
        Car m_car;
    public:
        Car* Build();
    protected:
        virtual void BuildManufactory() = 0;
        virtual void BuildEngine() = 0;
        virtual void BuildChassis() = 0;
        virtual void BuildWheel() = 0;
    };

#endif  /* CAR_BUILDER_BASE_H */
