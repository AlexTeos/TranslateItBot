QT -= gui
QT += network core sql

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEFINES += QT_MESSAGELOGCONTEXT

SOURCES += \
    languagestorage.cpp \
    log.cpp \
    main.cpp \
    sentencestorage.cpp \
    translateitapi.cpp \
    translateitbot.cpp \
    user.cpp \
    usercache.cpp \
    userstorage.cpp \
    userstoragedb.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    common.h \
    languagestorage.h \
    log.h \
    sentencestorage.h \
    translateitapi.h \
    translateitbot.h \
    user.h \
    usercache.h \
    userstorage.h \
    userstoragedb.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/TelegramAPI/src/release/ -ltelegramapi
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/TelegramAPI/src/debug/ -ltelegramapi
else:unix:!macx: LIBS += -L$$OUT_PWD/TelegramAPI/src/ -ltelegramapi

INCLUDEPATH += $$PWD/TelegramAPI/src
DEPENDPATH += $$PWD/TelegramAPI/src
