QT += qml quick svg quickcontrols2

CONFIG += c++11

SOURCES += main.cpp \
    handlersignals.cpp

RESOURCES += qml.qrc \
    HarrixQML.qrc

QML_IMPORT_PATH =

include(deployment.pri)

HEADERS += \
    handlersignals.h

VERSION = 1.0

RC_ICONS = harrix.ico

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
