TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Resume.cpp \
        ResumePtr.cpp \
        WorkExperience.cpp \
        main.cpp \
        shadow_deep_copy.cpp \
        testing.cpp

HEADERS += \
    ICloneable.h \
    Resume.h \
    ResumePtr.h \
    WorkExperience.h \
    shadow_deep_copy.h \
    testing.h
