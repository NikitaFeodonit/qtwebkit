# -------------------------------------------------------------------
# This file contains shared rules used both when building WebKit2
# itself, and by targets that use WebKit2.
#
# See 'Tools/qmake/README' for an overview of the build system
# -------------------------------------------------------------------

SOURCE_DIR = $${ROOT_WEBKIT_DIR}/Source/WebKit2

WEBKIT2_GENERATED_SOURCES_DIR = $${ROOT_BUILD_DIR}/Source/WebKit2/$${GENERATED_SOURCES_DESTDIR}

INCLUDEPATH += \
    $$SOURCE_DIR \
    $$SOURCE_DIR/Platform \
    $$SOURCE_DIR/Platform/CoreIPC \
    $$SOURCE_DIR/Platform/qt \
    $$SOURCE_DIR/Shared \
    $$SOURCE_DIR/Shared/linux/SandboxProcess \
    $$SOURCE_DIR/Shared/API/c \
    $$SOURCE_DIR/Shared/Authentication \
    $$SOURCE_DIR/Shared/CoordinatedGraphics \
    $$SOURCE_DIR/Shared/CoreIPCSupport \
    $$SOURCE_DIR/Shared/Downloads \
    $$SOURCE_DIR/Shared/Downloads/qt

INCLUDEPATH += \
    $$SOURCE_DIR/Shared/Network

INCLUDEPATH += \
    $$SOURCE_DIR/Shared/Plugins \
    $$SOURCE_DIR/Shared/Plugins/Netscape

INCLUDEPATH += \
    $$SOURCE_DIR/Shared/qt \
    $$SOURCE_DIR/UIProcess \
    $$SOURCE_DIR/UIProcess/API/C \
    $$SOURCE_DIR/UIProcess/API/C/qt \
    $$SOURCE_DIR/UIProcess/API/cpp \
    $$SOURCE_DIR/UIProcess/API/cpp/qt \
    $$SOURCE_DIR/UIProcess/API/qt \
    $$SOURCE_DIR/UIProcess/Authentication

INCLUDEPATH += \
    $$SOURCE_DIR/UIProcess/CoordinatedGraphics

INCLUDEPATH += \
    $$SOURCE_DIR/UIProcess/Downloads

INCLUDEPATH += \
    $$SOURCE_DIR/UIProcess/InspectorServer \
    $$SOURCE_DIR/UIProcess/InspectorServer/qt

INCLUDEPATH += \
    $$SOURCE_DIR/UIProcess/Launcher

INCLUDEPATH += \
    $$SOURCE_DIR/UIProcess/Notifications

INCLUDEPATH += \
    $$SOURCE_DIR/UIProcess/Plugins

INCLUDEPATH += \
    $$SOURCE_DIR/UIProcess/Storage

INCLUDEPATH += \
    $$SOURCE_DIR/UIProcess/qt

INCLUDEPATH += \
    $$SOURCE_DIR/UIProcess/texmap

INCLUDEPATH += \
    $$SOURCE_DIR/WebProcess \
    $$SOURCE_DIR/WebProcess/ApplicationCache \
    $$SOURCE_DIR/WebProcess/Battery

INCLUDEPATH += \
    $$SOURCE_DIR/WebProcess/Cookies \
    $$SOURCE_DIR/WebProcess/Cookies/qt

INCLUDEPATH += \
    $$SOURCE_DIR/WebProcess/FullScreen

INCLUDEPATH += \
    $$SOURCE_DIR/WebProcess/Geolocation

INCLUDEPATH += \
    $$SOURCE_DIR/WebProcess/IconDatabase

INCLUDEPATH += \
    $$SOURCE_DIR/WebProcess/InjectedBundle \
    $$SOURCE_DIR/WebProcess/InjectedBundle/DOM \
    $$SOURCE_DIR/WebProcess/InjectedBundle/API/c

INCLUDEPATH += \
    $$SOURCE_DIR/WebProcess/MediaCache

INCLUDEPATH += \
    $$SOURCE_DIR/WebProcess/NetworkInfo

INCLUDEPATH += \
    $$SOURCE_DIR/WebProcess/Notifications

INCLUDEPATH += \
    $$SOURCE_DIR/WebProcess/Plugins \
    $$SOURCE_DIR/WebProcess/Plugins/Netscape

INCLUDEPATH += \
    $$SOURCE_DIR/WebProcess/ResourceCache

INCLUDEPATH += \
    $$SOURCE_DIR/WebProcess/Storage

INCLUDEPATH += \
    $$SOURCE_DIR/WebProcess/WebCoreSupport \
    $$SOURCE_DIR/WebProcess/WebCoreSupport/qt \
    $$SOURCE_DIR/WebProcess/WebPage \
    $$SOURCE_DIR/WebProcess/WebPage/CoordinatedGraphics \
    $$SOURCE_DIR/WebProcess/qt

INCLUDEPATH += \
    $$SOURCE_DIR/PluginProcess

# The WebKit2 Qt APIs depend on qwebkitglobal.h, which lives in WebKit
INCLUDEPATH += $${ROOT_WEBKIT_DIR}/Source/WebKit/qt/Api

INCLUDEPATH += $${ROOT_WEBKIT_DIR}/Source/WTF/wtf/qt

INCLUDEPATH += $$WEBKIT2_GENERATED_SOURCES_DIR

linux-*:!android {
    # -lrt is required for shm_open and shm_unlink.
    LIBS += -lrt
}

have?(QTQUICK): QT += qml quick

have?(qtpositioning):enable?(GEOLOCATION): QT += positioning

enable?(SECCOMP_FILTERS): PKGCONFIG += libseccomp
