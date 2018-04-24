#-------------------------------------------------
#
# Project created by QtCreator 2018-04-24T15:12:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = view
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Doubler/release/ -lDoubler
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Doubler/debug/ -lDoubler
else:unix: LIBS += -L$$OUT_PWD/../Doubler/ -lDoubler

INCLUDEPATH += $$PWD/../Doubler
DEPENDPATH += $$PWD/../Doubler

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Doubler/release/libDoubler.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Doubler/debug/libDoubler.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Doubler/release/Doubler.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Doubler/debug/Doubler.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Doubler/libDoubler.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Tripler/release/ -lTripler
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Tripler/debug/ -lTripler
else:unix: LIBS += -L$$OUT_PWD/../Tripler/ -lTripler

INCLUDEPATH += $$PWD/../Tripler
DEPENDPATH += $$PWD/../Tripler
