#ifndef ASSEMBLING_CAR_H
#define ASSEMBLING_CAR_H

    #include <memory>
    using namespace std;
    #include "../Simple_Factory/CarBase.h"

    class AssemblingCar;
    class Engine;
    class Chassis;
    class Wheel;

    class AssemblingCar : public CarBase
    {
    public:
        AssemblingCar(Engine* pengine, Chassis* pchassis, Wheel* pwheel);
        void PrintName() override;
    private:
        shared_ptr<Engine> m_ptrEngine;
        shared_ptr<Chassis> m_ptrChassis;
        shared_ptr<Wheel> m_ptrWheel;
    };

#endif  /* ASSEMBLING_CAR_H */
