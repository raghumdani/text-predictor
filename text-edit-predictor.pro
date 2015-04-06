#-------------------------------------------------
#
# Project created by QtCreator 2015-04-06T10:23:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = text-edit-predictor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    trie_node.cpp \
    trie.cpp \
    editdistance.cpp

HEADERS  += mainwindow.h \
    trie.h \
    trie_node.h \
    editdistance.h

FORMS    += mainwindow.ui
