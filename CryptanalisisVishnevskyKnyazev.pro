# -------------------------------------------------
# Project created by QtCreator 2017-03-05T23:58:45
# -------------------------------------------------
# add -m64 to flags for 64-bit Intel
# CXXFLAGS=-g -DDEBUG -I../include -I. -c
# LDFLAGS=-g
CXXFLAGS = -O2 \
    -I../../ntl-5.5.2/include \
    -I. \
    -DNO_DEBUG \
    -DNO_TIMER
LDFLAGS = -O2 \
    -L../..//msys/1.0/local/lib/
QT -= core \
    gui
TARGET = CryptanalisisVishnevskyKnyazev
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
INCLUDEPATH += "WinNTL-5_5_2\include" \
    "WinNTL-5_5_2\src"

# LIBS += "WinNTL-5_5_2\lib\libNTL.a"
LIBS += "WinNTL-5_5_2\NTL\release\libNTL.a"
SOURCES += main.cpp \
    Utility.cpp \
    VishnevskiyCryptosystem.cpp \
    VishnevskiyCryptosystemTest.cpp \
    VishnevskyCryptosystemKPA.cpp \
    time_measurement.cpp \
    PrimeGenerator.cpp
HEADERS += Utility.h \
    VishnevskiyCryptosystem.h \
    VishnevskiyCryptosystemTest.h \
    VishnevskyCryptosystemKPA.h \
    PrimeGenerator.h \
    time_measurement.h
