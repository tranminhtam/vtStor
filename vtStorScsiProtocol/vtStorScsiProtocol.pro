#-------------------------------------------------
#
# Project created by QtCreator 2015-12-22T17:30:33
#
#-------------------------------------------------

TARGET = vtStorScsiProtocol
TEMPLATE = lib
QMAKE_CXXFLAGS += -std=c++14
QMAKE_CXXFLAGS += -fpermissive

DEFINES += VTSTORSCSIPROTOCOL_LIBRARY

SOURCES += \
    ScsiProtocolEssense1.cpp \
    Platform/Linux/ProtocolScsiPassThrough.cpp

HEADERS += \
    ScsiProtocolEssense1.h \
    Platform/Linux/vtStorScsiProtocolPlatformDefines.h \
    Platform/Linux/ProtocolScsiPassThrough.h

INCLUDEPATH += "../../vtStorScsiProtocol/Platform/Linux" "../../Common" "../../Common/Platform/x86x64" "../../Common/Platform/x86x64/Linux" "../../StorageUtility" "../../StorageUtility/Linux" "../../vtStor" "../../vtStor/Platform/Linux"

CONFIG(debug, debug|release) {

    unix:!macx:!symbian: LIBS += -L$$PWD/../Build_StorageUtility/Debug/ -lStorageUtility

    INCLUDEPATH += $$PWD/../Build_StorageUtility/Debug
    DEPENDPATH += $$PWD/../Build_StorageUtility/Debug

    unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../Build_StorageUtility/Debug/libStorageUtility.a

    unix:!macx:!symbian: LIBS += -L$$PWD/../Build_vtStor/Debug/ -lvtStor

    INCLUDEPATH += $$PWD/../Build_vtStor/Debug
    DEPENDPATH += $$PWD/../Build_vtStor/Debug
}

CONFIG(release, debug|release) {

    unix:!macx:!symbian: LIBS += -L$$PWD/../Build_StorageUtility/Release/ -lStorageUtility

I   NCLUDEPATH += $$PWD/../Build_StorageUtility/Release
    DEPENDPATH += $$PWD/../Build_StorageUtility/Release

    unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../Build_StorageUtility/Release/libStorageUtility.a

     unix:!macx:!symbian: LIBS += -L$$PWD/../Build_vtStor/Release/ -lvtStor

    INCLUDEPATH += $$PWD/../Build_vtStor/Release
    DEPENDPATH += $$PWD/../Build_vtStor/Release

}