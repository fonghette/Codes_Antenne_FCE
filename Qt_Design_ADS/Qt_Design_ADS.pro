QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    Qt_Design_ADS_fr_FR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -L$$PWD/'../../../../../../Program Files (x86)/Windows Kits/8.1/Lib/winv6.3/um/x64/' -lshell32

INCLUDEPATH += $$PWD/'../../../../../../Program Files (x86)/Windows Kits/8.1/Lib/winv6.3/um/x64'
DEPENDPATH += $$PWD/'../../../../../../Program Files (x86)/Windows Kits/8.1/Lib/winv6.3/um/x64'

unix|win32: LIBS += -L$$PWD/../../../../../../TwinCAT/AdsApi/TcAdsDll/x64/lib/ -lTcAdsDll

INCLUDEPATH += $$PWD/../../../../../../TwinCAT/AdsApi/TcAdsDll/x64
DEPENDPATH += $$PWD/../../../../../../TwinCAT/AdsApi/TcAdsDll/x64
