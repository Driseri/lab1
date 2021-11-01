QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acid.cpp \
    acidprot.cpp \
    add.cpp \
    delete.cpp \
    exp.cpp \
    exportwindow.cpp \
    imp.cpp \
    importwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    printsum.cpp \
    protein.cpp \
    show.cpp \
    sum.cpp \
    sumwindow.cpp

HEADERS += \
    acid.h \
    acidprot.h \
    add.h \
    delete.h \
    exp.h \
    exportwindow.h \
    imp.h \
    importwindow.h \
    mainwindow.h \
    printsum.h \
    protein.h \
    show.h \
    sum.h \
    sumwindow.h

FORMS += \
    add.ui \
    delete.ui \
    exp.ui \
    exportwindow.ui \
    imp.ui \
    importwindow.ui \
    mainwindow.ui \
    printsum.ui \
    show.ui \
    sum.ui \
    sumwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    input.txt \
    output.txt
