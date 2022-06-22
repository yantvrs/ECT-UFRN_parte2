TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        cutbox.cpp \
        cutellipsoid.cpp \
        cutsphere.cpp \
        cutvoxel.cpp \
        figurageometrica.cpp \
        main.cpp \
        putellipsoid.cpp \
        putsphere.cpp \
        putvoxel.cpp \
        sculptor.cpp \
        putbox.cpp

HEADERS += \
    cutbox.h \
    cutellipsoid.h \
    cutsphere.h \
    cutvoxel.h \
    figurageometrica.h \
    putbox.h \
    putellipsoid.h \
    putsphere.h \
    putvoxel.h \
    sculptor.h
