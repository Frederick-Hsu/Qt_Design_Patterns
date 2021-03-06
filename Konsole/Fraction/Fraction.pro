QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    structure.cpp \
    client.cpp \
    fraction.cpp \
    Complex.cpp \
    Thing.cpp \
    circular/Chicken.cpp \
    circular/Egg.cpp \
    advanced/Point.cpp \
    advanced/Square.cpp \
    advanced/Employer.cpp \
    advanced/Person.cpp \
    advanced/Position.cpp \
    advanced/Date.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    structure.h \
    client.h \
    fraction.h \
    timer.h \
    Complex.h \
    Thing.h \
    circular/Chicken.h \
    circular/Egg.h \
    advanced/Point.h \
    advanced/Square.h \
    advanced/Employer.h \
    advanced/Person.h \
    advanced/Position.h \
    advanced/Hondurota.h \
    advanced/Date.h
