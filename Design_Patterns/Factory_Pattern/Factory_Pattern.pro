TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Abstract_Template_Factory/template_factory.cpp \
        Factory_Method/AssemblingCar.cpp \
        Factory_Method/AssemblingCarFactory.cpp \
        Factory_Method/CarFactories.cpp \
        Factory_Method/Components.cpp \
        Simple_Factory/Car.cpp \
        Simple_Factory/CarBase.cpp \
        Simple_Factory/CarFactory.cpp \
        main.cpp \
        test.cpp

HEADERS += \
    Abstract_Template_Factory/template_factory.h \
    Factory_Method/AssemblingCar.h \
    Factory_Method/AssemblingCarFactory.h \
    Factory_Method/CarFactories.h \
    Factory_Method/Components.h \
    Factory_Method/IFactory.h \
    Simple_Factory/Car.h \
    Simple_Factory/CarBase.h \
    Simple_Factory/CarFactory.h \
    test.h
