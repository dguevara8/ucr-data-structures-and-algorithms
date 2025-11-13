QT       += core gui
QT += quick location positioning
QT += widgets core gui quick location positioning
QT += quickwidgets
QT += core gui widgets
INCLUDEPATH += /home/danna/ProyectoEDAI_ReservaDeVuelos/src

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += c++17

# Configurar salida en build/
DESTDIR = ../../build
OBJECTS_DIR = ../../build
MOC_DIR = ../../build
RCC_DIR = ../../build
UI_DIR = ../../build

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agregarciudad.cpp \
    agregarvuelo.cpp \
    eliminarciudad.cpp \
    eliminarvuelo.cpp \
    modificarvuelo.cpp \
    ../main.cpp \
    mainwindow.cpp \

HEADERS += \
    agregarciudad.h \
    agregarvuelo.h \
    eliminarciudad.h \
    eliminarvuelo.h \
    modificarvuelo.h \
    mainwindow.h \

FORMS += \
    agregarciudad.ui \
    agregarvuelo.ui \
    eliminarciudad.ui \
    eliminarvuelo.ui \
    modificarvuelo.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Maps.qrc
