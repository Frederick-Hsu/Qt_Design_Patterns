#ifndef ASSEMBLING_CAR_FACTORY_H
#define ASSEMBLING_CAR_FACTORY_H

    #include "IFactory.h"

    class AssemblingCarFactory;

    class AssemblingCarFactory : public IFactory
    {
    public:
        CarBase* Create() override;
    };

    void AssemblingCarFactoryTest(void);

#endif  /* ASSEMBLING_CAR_FACTORY_H */
