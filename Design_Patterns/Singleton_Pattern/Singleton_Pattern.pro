TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    CSingleton.cpp \
    HungryManager.cpp \
    Manager.cpp \
    Meyers_Singleton_Pattern.cpp \
    main.cpp \
    singleton_thread_unsafe.cpp \
    testing.cpp

HEADERS += \
    CHungrySingleton.h \
    CSingleton.h \
    CSingletonPtr.h \
    HungryManager.h \
    Manager.h \
    Meyers_Singleton_Pattern.h \
    singleton_thread_unsafe.h \
    testing.h
