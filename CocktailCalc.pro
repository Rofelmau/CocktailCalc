#-------------------------------------------------
#
# Project created by QtCreator 2019-06-07T12:17:13
#
#-------------------------------------------------

QT       += core gui
QT       += uitools
QT      += network
QT      += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CocktailCalc
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    filedownloader.cpp \
        main.cpp \
        mainwindow.cpp \
    ingredient.cpp \
    position.cpp \
    container.cpp \
    cocktail.cpp

HEADERS += \
    filedownloader.h \
        mainwindow.h \
    ingredient.h \
    position.h \
    container.h \
    cocktail.h

FORMS += \
        mainwindow.ui

DISTFILES += \
    cocktailList.json

OTHER_FILES += \
    .gitignore
    
# Qt Creator linking

## set the QTC_SOURCE environment variable to override the setting here
QTCREATOR_SOURCES = $$QTC_SOURCE
unix:isEmpty(QTCREATOR_SOURCES):QTCREATOR_SOURCES=$$(HOME)/src/qt-creator-opensource-src-4.10.0
win32:isEmpty(QTCREATOR_SOURCES):QTCREATOR_SOURCES=C:\src\qt-creator-opensource-src-4.10.0

## set the QTC_BUILD environment variable to override the setting here
IDE_BUILD_TREE = $$QTC_BUILD
unix:isEmpty(IDE_BUILD_TREE):IDE_BUILD_TREE=$$(HOME)/Qt/Tools/QtCreator
win32:isEmpty(IDE_BUILD_TREE):IDE_BUILD_TREE=C:\src\build-qtcreator-Desktop_Qt_5_11_2_MSVC2015_32bit2-Release

## set the QTC_LIB_BASENAME environment variable to override the setting here
## this variable points to the library installation path, relative to IDE_BUILD_TREE,
## so that $$IDE_BUILD_TREE/$$IDE_LIBRARY_BASENAME/qtcreator will be used by
## qtcreatorplugin.pri automatically as the qtcreator library path
IDE_LIBRARY_BASENAME = $$(QTC_LIB_BASENAME)

## uncomment to build plugin into user config directory
## <localappdata>/plugins/<ideversion>
##    where <localappdata> is e.g.
##    "%LOCALAPPDATA%\QtProject\qtcreator" on Windows Vista and later
##    "$XDG_DATA_HOME/data/QtProject/qtcreator" or "~/.local/share/data/QtProject/qtcreator" on Linux
##    "~/Library/Application Support/QtProject/Qt Creator" on Mac
#USE_USER_DESTDIR = yes
