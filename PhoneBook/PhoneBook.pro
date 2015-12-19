#-------------------------------------------------
#
# Project created by QtCreator 2015-12-18T09:19:45
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PhoneBook
TEMPLATE = app


SOURCES += main.cpp\
        phonebook.cpp \
    addrecord.cpp \
    contact.cpp

HEADERS  += phonebook.h \
    addrecord.h \
    contact.h

FORMS    += phonebook.ui \
    addrecord.ui

RESOURCES += \
    icons/icons.qrc

QMAKE_CXXFLAGS += -std=gnu++11
