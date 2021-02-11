################################################################################
# FeedReader.pro                                                               #
# Copyright (C) 2018, Retroshare team <retroshare.team@gmailcom>               #
#                                                                              #
# This program is free software: you can redistribute it and/or modify         #
# it under the terms of the GNU Affero General Public License as               #
# published by the Free Software Foundation, either version 3 of the           #
# License, or (at your option) any later version.                              #
#                                                                              #
# This program is distributed in the hope that it will be useful,              #
# but WITHOUT ANY WARRANTY; without even the implied warranty of               #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                #
# GNU Lesser General Public License for more details.                          #
#                                                                              #
# You should have received a copy of the GNU Lesser General Public License     #
# along with this program.  If not, see <https://www.gnu.org/licenses/>.       #
################################################################################

!include("../Common/retroshare_plugin.pri"): error("Could not include file ../Common/retroshare_plugin.pri")

CONFIG += qt uic qrc resources
TARGET = FileInfoTaskbar
TARGET_PRL = FileInfoTaskbar
DESTDIR = lib

greaterThan(QT_MAJOR_VERSION, 4) {
	# Qt 5
	QT += widgets
}

target.files = lib/libfileinfotaskbar.so

SOURCES =	\
    FileInfoTaskbarConfig.cpp \
    FileInfoTaskbarPlugin.cpp \
    FileInfoTaskbarSettings.cpp \
    TaskbarHandler.cpp

HEADERS =	\
    FileInfoTaskbarConfig.h \
    FileInfoTaskbarPlugin.h \
    FileInfoTaskbarSettings.h \
    TaskbarHandler.h

FORMS = \
    FileInfoTaskbarConfig.ui

TARGET = FileInfoTaskbar

RESOURCES =

TRANSLATIONS +=

win32 {
    QT += winextras
} else {
    error("Windows only")
}
