#####################################################################
 # QJSON : A Qt5 like JSON library that can be used in Qt 4.8+
 # Copyright (C) 2012-2014  S.M.Mohammadzadeh <mehran.m@aut.ac.ir>
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

# +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-#
BASE_HEADERS += \
    libQJSON/JSONArray.h \
    libQJSON/JSONDocument.h \
    libQJSON/JSONParseError.h \
    libQJSON/JSONObject.h \
    libQJSON/JSONValue.h

HEADERS += \
    $$BASE_HEADERS \
    libQJSON/Private/qjsonwriter_p.h \
    libQJSON/Private/qjsonparser_p.h \
    libQJSON/Private/qjson_p.h

# +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-#
SOURCES += \
    libQJSON/Private/qjsonwriter.cpp \
    libQJSON/Private/qjsonvalue.cpp \
    libQJSON/Private/qjsonparser.cpp \
    libQJSON/Private/qjsonobject.cpp \
    libQJSON/Private/qjsondocument.cpp \
    libQJSON/Private/qjsonarray.cpp \
    libQJSON/Private/qjson.cpp


# #########################################################
# ###          Do Not Change Anything Below            ####
# #########################################################
TEMPLATE = lib
TARGET = $$ProjectName
DESTDIR = $$BasePath/out/lib/
OBJECTS_DIR = $$BasePath/out/build/obj
MOC_DIR = $$BasePath/out/build/moc

QMAKE_CXXFLAGS_RELEASE += -fPIC
QMAKE_CXXFLAGS_DEBUG += -fPIC

unix{
  prefix = $$(HOME)/local/
  target.files= out/lib/
  target.path = $$prefix

  header_files.files = $$BASE_HEADERS
  header_files.path = $$prefix/include

#  system("mkdir -p $$prefix/include")
  INSTALLS += target header_files
}


