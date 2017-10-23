#-------------------------------------------------
#
# Project created by QtCreator 2017-10-13T16:55:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = book
TEMPLATE = app


SOURCES += \
        main.cpp\
        mainwindow.cpp \
    categorymange.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    categorymange.h \
    dialog.h \
#    include/crypt.h \
#    include/ioapi.h \
#    include/JlCompress.h \
#    include/quaadler32.h \
#    include/quachecksum32.h \
#    include/quacrc32.h \
#    include/quagzipfile.h \
#    include/quaziodevice.h \
#    include/quazip.h \
#    include/quazip_global.h \
#    include/quazipdir.h \
#    include/quazipfile.h \
#    include/quazipfileinfo.h \
#    include/quazipnewinfo.h \
#    include/unzip.h \
#    include/zip.h


FORMS    += mainwindow.ui \
    categorymange.ui \
    dialog.ui

DEFINES += QT_DEPRECATED_WARNINGS

RESOURCES += \
    iconfile.qrc


CONFIG   += qaxcontainer

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/include/ -lquazip
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/include/ -lquazipd
else:unix: LIBS += -L$$PWD/include/ -lquazip

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include
