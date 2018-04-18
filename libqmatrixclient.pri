QT += network
CONFIG += c++14 warn_on rtti_off create_prl

win32-msvc* {
    QMAKE_CXXFLAGS_WARN_ON += -wd4100
} else {
    QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
}

SRCPATH = $$PWD/lib
INCLUDEPATH += $$SRCPATH

HEADERS += \
    $$SRCPATH/connectiondata.h \
    $$SRCPATH/connection.h \
    $$SRCPATH/room.h \
    $$SRCPATH/user.h \
    $$SRCPATH/avatar.h \
    $$SRCPATH/util.h \
    $$SRCPATH/events/event.h \
    $$SRCPATH/events/eventcontent.h \
    $$SRCPATH/events/roommessageevent.h \
    $$SRCPATH/events/simplestateevents.h \
    $$SRCPATH/events/roommemberevent.h \
    $$SRCPATH/events/roomavatarevent.h \
    $$SRCPATH/events/typingevent.h \
    $$SRCPATH/events/receiptevent.h \
    $$SRCPATH/events/accountdataevents.h \
    $$SRCPATH/events/redactionevent.h \
    $$SRCPATH/jobs/basejob.h \
    $$SRCPATH/jobs/checkauthmethods.h \
    $$SRCPATH/jobs/passwordlogin.h \
    $$SRCPATH/jobs/sendeventjob.h \
    $$SRCPATH/jobs/postreceiptjob.h \
    $$SRCPATH/jobs/joinroomjob.h \
    $$SRCPATH/jobs/roommessagesjob.h \
    $$SRCPATH/jobs/syncjob.h \
    $$SRCPATH/jobs/mediathumbnailjob.h \
    $$SRCPATH/jobs/setroomstatejob.h \
    $$SRCPATH/jobs/postreadmarkersjob.h \
    $$files($$SRCPATH/jobs/generated/*.h, false) \
    $$SRCPATH/logging.h \
    $$SRCPATH/settings.h

SOURCES += \
    $$SRCPATH/connectiondata.cpp \
    $$SRCPATH/connection.cpp \
    $$SRCPATH/room.cpp \
    $$SRCPATH/user.cpp \
    $$SRCPATH/avatar.cpp \
    $$SRCPATH/events/event.cpp \
    $$SRCPATH/events/eventcontent.cpp \
    $$SRCPATH/events/roommessageevent.cpp \
    $$SRCPATH/events/roommemberevent.cpp \
    $$SRCPATH/events/typingevent.cpp \
    $$SRCPATH/events/receiptevent.cpp \
    $$SRCPATH/jobs/basejob.cpp \
    $$SRCPATH/jobs/checkauthmethods.cpp \
    $$SRCPATH/jobs/passwordlogin.cpp \
    $$SRCPATH/jobs/sendeventjob.cpp \
    $$SRCPATH/jobs/postreceiptjob.cpp \
    $$SRCPATH/jobs/joinroomjob.cpp \
    $$SRCPATH/jobs/roommessagesjob.cpp \
    $$SRCPATH/jobs/syncjob.cpp \
    $$SRCPATH/jobs/mediathumbnailjob.cpp \
    $$SRCPATH/jobs/setroomstatejob.cpp \
    $$files($$SRCPATH/jobs/generated/*.cpp, false) \
    $$SRCPATH/logging.cpp \
    $$SRCPATH/settings.cpp
