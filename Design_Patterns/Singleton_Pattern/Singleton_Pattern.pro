TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    CSingleton.cpp \
    Manager.cpp \
    Meyers_Singleton_Pattern.cpp \
    main.cpp \
    singleton_thread_unsafe.cpp \
    testing.cpp

HEADERS += \
    CSingleton.h \
    CSingletonPtr.h \
    Manager.h \
    Meyers_Singleton._Pattern.h \
    singleton_thread_unsafe.h \
    testing.h
