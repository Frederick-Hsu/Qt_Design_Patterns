#include "CarBuilderBase.h"

Car* CarBuilderBase::Build()
{
    BuildManufactory();
    BuildEngine();
    BuildChassis();
    BuildWheel();
    return &m_car;
}
