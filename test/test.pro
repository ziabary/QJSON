#####################################################################
 # QJSON : A Qt5 like JSON library that can be used in Qt 4.8+
 # Copyright (C) 2012-2014  S.Mohammad M. Ziabary <mehran.m@aut.ac.ir>
 #
 # This program is free software; you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
 # the Free Software Foundation; either version 2 of the License, or
 # (at your option) any later version.

 # This program is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 # GNU General Public License for more details.

 # You should have received a copy of the GNU General Public License along
 # with this program; if not, write to the Free Software Foundation, Inc.,
 # 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
#####################################################################
ProjectName = "QJSON"
BasePath = ".."

#+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-#
HEADERS +=
#+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-#
SOURCES += main.cpp


##########################################################
####          Do Not Change Anything Below            ####
##########################################################
TEMPLATE = app
TARGET = test
DESTDIR = $$BasePath/out/
OBJECTS_DIR = $$BasePath/out/build/obj
MOC_DIR = $$BasePath/out/build/moc

QT += core
QT -= gui

INCLUDEPATH += $$BasePath/src
QMAKE_LIBDIR += $$BasePath/out/lib/
LIBS += -l$$ProjectName
