QT += core opengl widgets

#Set CONFIG to Qt
CONFIG += qt

#Use to display printf results to the console
win32 
{
    CONFIG += console
}

#TARGET is optional and used to change the name of the executable
TARGET = Assignment1

#Add HEADERS and SOURCES as shown below

HEADERS += GLWidget.h \
    LineDialog.h \
    linestyle.h
HEADERS +=
HEADERS += PrintDialog.h
HEADERS += Window.h
HEADERS += MainWindow.h
HEADERS += DrawingAlgorithms.h

SOURCES += main.cpp \
    LineDialog.cpp \
    linestyle.cpp
SOURCES += Window.cpp
SOURCES += MainWindow.cpp
SOURCES += GLWidget.cpp
SOURCES +=
SOURCES += PrintDialog.cpp
SOURCES += DrawingAlgorithms.cpp
