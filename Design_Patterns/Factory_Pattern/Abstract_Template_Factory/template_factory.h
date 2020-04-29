#ifndef TEMPLATE_FACTORY_H
#define TEMPLATE_FACTORY_H

    class STCarFactory;
    class STCarBaseFactory;
    class CarBase;

    class STCarFactory
    {
    public:
        template<class T> static T* Create();
    };

    class STCarBaseFactory
    {
    public:
        template<class T> static CarBase* Create();
    };

    void STCarFactoryTest(void);
    void STCarBaseFactoryTest(void);

#endif  /* TEMPLATE_FACTORY_H */
