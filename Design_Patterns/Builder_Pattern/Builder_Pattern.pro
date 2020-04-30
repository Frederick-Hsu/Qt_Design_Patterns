TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Car.cpp \
        CarBuilder.cpp \
        CarBuilderBase.cpp \
        main.cpp \
        testing.cpp

HEADERS += \
    Car.h \
    CarBuilder.h \
    CarBuilderBase.h \
    testing.h
