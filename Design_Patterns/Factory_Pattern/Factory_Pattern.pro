TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Factory_Method/CarFactories.cpp \
        Simple_Factory/Car.cpp \
        Simple_Factory/CarBase.cpp \
        Simple_Factory/CarFactory.cpp \
        main.cpp \
        test.cpp

HEADERS += \
    Factory_Method/CarFactories.h \
    Factory_Method/IFactory.h \
    Simple_Factory/Car.h \
    Simple_Factory/CarBase.h \
    Simple_Factory/CarFactory.h \
    test.h
