#-------------------------------------------------
#
# Project created by QtCreator 2019-10-05T14:40:23
#
#-------------------------------------------------

QT       += core gui
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CampusGuide_DP_QT
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Information.cpp \
        addinform.cpp \
        bjutmap.cpp \
        frmmain.cpp \
        inquiry.cpp \
        main.cpp \
        myEmailTools/sendemailapi/emailaddress.cpp \
        myEmailTools/sendemailapi/mimeattachment.cpp \
        myEmailTools/sendemailapi/mimecontentformatter.cpp \
        myEmailTools/sendemailapi/mimefile.cpp \
        myEmailTools/sendemailapi/mimehtml.cpp \
        myEmailTools/sendemailapi/mimeinlinefile.cpp \
        myEmailTools/sendemailapi/mimemessage.cpp \
        myEmailTools/sendemailapi/mimemultipart.cpp \
        myEmailTools/sendemailapi/mimepart.cpp \
        myEmailTools/sendemailapi/mimetext.cpp \
        myEmailTools/sendemailapi/quotedprintable.cpp \
        myEmailTools/sendemailapi/smtpclient.cpp \
        profession.cpp \
        recommend.cpp

HEADERS += \
        Information.h \
        addinform.h \
        alldistancedata.h \
        bjutmap.h \
        frmmain.h \
        inquiry.h \
        introduction.h \
        myEmailTools/sendemailapi/emailaddress.h \
        myEmailTools/sendemailapi/mimeattachment.h \
        myEmailTools/sendemailapi/mimecontentformatter.h \
        myEmailTools/sendemailapi/mimefile.h \
        myEmailTools/sendemailapi/mimehtml.h \
        myEmailTools/sendemailapi/mimeinlinefile.h \
        myEmailTools/sendemailapi/mimemessage.h \
        myEmailTools/sendemailapi/mimemultipart.h \
        myEmailTools/sendemailapi/mimepart.h \
        myEmailTools/sendemailapi/mimetext.h \
        myEmailTools/sendemailapi/quotedprintable.h \
        myEmailTools/sendemailapi/smtpclient.h \
        myEmailTools/sendemailapi/smtpmime.h \
        process.h \
        profession.h \
        recommend.h \
        subject.h

FORMS += \
        Information.ui \
        addinform.ui \
        bjutmap.ui \
        frmmain.ui \
        inquiry.ui \
        profession.ui \
        recommend.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

QT += network

DISTFILES += \
    Resource/icon12_1.png \
    Resource/icon4_1.png
