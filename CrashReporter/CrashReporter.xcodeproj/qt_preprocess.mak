#############################################################################
# Makefile for building: CrashReporter.app/Contents/MacOS/CrashReporter
# Generated by qmake (2.01a) (Qt 4.8.7) on: mar. mai 3 16:52:54 2016
# Project:  CrashReporter.pro
# Template: app
# Command: /usr/local/bin/qmake -spec /usr/local/Cellar/qt/4.8.7_2/mkspecs/macx-xcode CONFIG+=debug CONFIG+=nopch -o CrashReporter.xcodeproj/project.pbxproj CrashReporter.pro
#############################################################################

MOC       = /usr/local/Cellar/qt/4.8.7_2/bin/moc
UIC       = /usr/local/Cellar/qt/4.8.7_2/bin/uic
LEX       = flex
LEXFLAGS  = 
YACC      = yacc
YACCFLAGS = -d
DEFINES       = 
INCPATH       = -I/usr/local/Cellar/qt/4.8.7_2/mkspecs/macx-xcode -I. -I/usr/local/include -I/System/Library/Frameworks/CarbonCore.framework/Headers
DEL_FILE  = rm -f
MOVE      = mv -f

IMAGES = 
PARSERS =
preprocess: $(PARSERS) compilers
clean preprocess_clean: parser_clean compiler_clean

parser_clean: