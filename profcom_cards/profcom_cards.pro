#-------------------------------------------------
#
# Project created by QtCreator 2015-12-08T13:34:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = profcom_cards
TEMPLATE = app


SOURCES += main.cpp\
        profkom.cpp

HEADERS  += profkom.h

FORMS    += profkom.ui

QT += sql

QT +=network

CONFIG += qsqlmysql

QT += core

