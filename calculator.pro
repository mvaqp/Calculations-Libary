QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calculator
TEMPLATE = app

SOURCES += main.cpp \
    calculator.cpp

HEADERS += calculator.h

FORMS += calculator.ui
