#ifndef IFACTORY_H
#define IFACTORY_H

    class IFactory;
    class CarBase;

    class IFactory
    {
    public:
        virtual CarBase* Create() = 0;
    };

#endif  /* IFACTORY_H */
