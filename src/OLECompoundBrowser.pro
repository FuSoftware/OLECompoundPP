TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ole/olestorage.cpp \
    ole/olefile.cpp \
    ole/olestream.cpp \
    ole/oleutils.cpp \
    ole/oleheader.cpp \
    ole/olemsat.cpp \
    fhx/fhxfile.cpp \
    fhx/fhxitem.cpp \
    fhx/fhxparameter.cpp \
    fhx/fhxparser.cpp

HEADERS += \
    ole/olestorage.h \
    ole/olefile.h \
    ole/olestream.h \
    ole/oleutils.h \
    ole/oleheader.h \
    ole/olemsat.h \
    fhx/fhxfile.h \
    fhx/fhxitem.h \
    fhx/fhxparameter.h \
    fhx/fhxparser.h
