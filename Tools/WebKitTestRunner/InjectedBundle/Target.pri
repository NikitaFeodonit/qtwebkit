# -------------------------------------------------------------------
# Project file for WebKitTestRunner's InjectedBundle
#
# See 'Tools/qmake/README' for an overview of the build system
# -------------------------------------------------------------------

CFG_FILE_INB_TARGET_PRI = Tools\WebKitTestRunner\InjectedBundle\Target.pri
cfg_dwarning_file_in($$CFG_FILE_INB_TARGET_PRI)

TEMPLATE = lib
TARGET = WTRInjectedBundle

SOURCES += \
    AccessibilityController.cpp \
    AccessibilityTextMarker.cpp \
    AccessibilityTextMarkerRange.cpp \
    AccessibilityUIElement.cpp \
    InjectedBundle.cpp \
    InjectedBundle.h \
    InjectedBundleMain.cpp \
    InjectedBundlePage.cpp \
    InjectedBundlePage.h \
    EventSendingController.cpp \
    EventSendingController.h \
    GCController.cpp \
    GCController.h \
    TestRunner.cpp \
    TestRunner.h \
    TextInputController.cpp \
    TextInputController.h \
    Bindings/JSWrapper.cpp \
    qt/ActivateFontsQt.cpp \
    qt/InjectedBundleQt.cpp \
    qt/TestRunnerQt.cpp

# Adds the generated sources to SOURCES
include(DerivedSources.pri)

HEADERS += \
    AccessibilityController.h \
    AccessibilityTextMarker.h \
    AccessibilityTextMarkerRange.h \
    AccessibilityUIElement.h \
    ActivateFonts.h \
    EventSendingController.h \
    GCController.h \
    InjectedBundle.h \
    InjectedBundlePage.h \
    TestRunner.h \
    TextInputController.h \

DESTDIR = $${ROOT_BUILD_DIR}/lib

QT += widgets webkit

WEBKIT += wtf

cfg_enable?(CFG_JAVASCRIPTCORE) {
    WEBKIT += javascriptcore
}

WEBKIT += webcore

CONFIG += plugin rpath

have?(FONTCONFIG): PKGCONFIG += fontconfig

INCLUDEPATH += \
    $$PWD \
    $$PWD/.. \
    $$PWD/Bindings \
    $${ROOT_WEBKIT_DIR}/Source/WebCore/platform/qt

cfg_enable?(CFG_JAVASCRIPTCORE) {
  INCLUDEPATH += \
    $${ROOT_WEBKIT_DIR}/Source/WebCore/testing/js
}

INCLUDEPATH += \
    $${ROOT_WEBKIT_DIR}/Source/WebKit/qt/WebCoreSupport

PREFIX_HEADER = $$PWD/../WebKitTestRunnerPrefix.h
*-g++*:QMAKE_CXXFLAGS += "-include $$PREFIX_HEADER"

linux-* {
    QMAKE_LFLAGS += -Wl,--no-undefined
}

cfg_dwarning_file_out($$CFG_FILE_INB_TARGET_PRI)
