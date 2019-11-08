#-------------------------------------------------
#
# Project created by QtCreator 2019-08-13T16:10:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QontainerAccessoriPC
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
QMAKE_CXXFLAGS += -std=c++11
CONFIG += c++11

SOURCES += main.cpp \
    Contenitore/AccessoriPc/accessori.cpp \
    Contenitore/AccessoriPc/cuffie.cpp \
    Contenitore/AccessoriPc/monitor.cpp \
    Contenitore/AccessoriPc/mouse.cpp \
    Contenitore/AccessoriPc/tastiera.cpp \
    Contenitore/AccessoriPc/webcam.cpp \
    SL/readerxmltag.cpp \
    SL/xmlio.cpp \
    View/AccessoriData/QComboBoxNewAccessori/cbcategoriatastiera.cpp \
    View/AccessoriData/QComboBoxNewAccessori/cbconforttastiera.cpp \
    View/AccessoriData/QComboBoxNewAccessori/cbdr.cpp \
    View/AccessoriData/QComboBoxNewAccessori/cbergonomiamouse.cpp \
    View/AccessoriData/QComboBoxNewAccessori/cblayouttastiera.cpp \
    View/AccessoriData/QComboBoxNewAccessori/cbmicwebcam.cpp \
    View/AccessoriData/QComboBoxNewAccessori/cbmonth.cpp \
    View/AccessoriData/QComboBoxNewAccessori/cbrapportdaspettomonitor.cpp \
    View/AccessoriData/QComboBoxNewAccessori/cbrisoluzionemonitor.cpp \
    View/AccessoriData/QComboBoxNewAccessori/cbsensoremouse.cpp \
    View/AccessoriData/QComboBoxNewAccessori/cbtype.cpp \
    View/AccessoriData/cuffie_stampamodificadati.cpp \
    View/AccessoriData/monitor_stampamodificadati.cpp \
    View/AccessoriData/mouse_stampamodificadati.cpp \
    View/AccessoriData/newcuffielayout.cpp \
    View/AccessoriData/newmonitorlayout.cpp \
    View/AccessoriData/newmouselayout.cpp \
    View/AccessoriData/newtastieralayout.cpp \
    View/AccessoriData/newwebcamlayout.cpp \
    View/AccessoriData/tastiera_stampamodificadati.cpp \
    View/AccessoriData/webcam_stampamodificadati.cpp \
    View/LayoutView-QualityResearch/layoutquality.cpp \
    View/LayoutView-QualityResearch/layoutresearch.cpp \
    View/home.cpp \
    View/layoutdatiaccessorio.cpp \
    View/layoutinserisciarticolo.cpp \
    View/layoutlistaricercaaccessori.cpp \
    View/menubar.cpp \
    View/mwindow.cpp \
    View/notvalidexception.cpp \
    model.cpp

HEADERS  += \
    Contenitore/AccessoriPc/accessori.h \
    Contenitore/AccessoriPc/cuffie.h \
    Contenitore/AccessoriPc/monitor.h \
    Contenitore/AccessoriPc/mouse.h \
    Contenitore/AccessoriPc/tastiera.h \
    Contenitore/AccessoriPc/webcam.h \
    Contenitore/container.h \
    Contenitore/deepptr.h \
    SL/readerxmltag.h \
    SL/xmlio.h \
    View/AccessoriData/QComboBoxNewAccessori/cbcategoriatastiera.h \
    View/AccessoriData/QComboBoxNewAccessori/cbconforttastiera.h \
    View/AccessoriData/QComboBoxNewAccessori/cbdr.h \
    View/AccessoriData/QComboBoxNewAccessori/cbergonomiamouse.h \
    View/AccessoriData/QComboBoxNewAccessori/cblayouttastiera.h \
    View/AccessoriData/QComboBoxNewAccessori/cbmicwebcam.h \
    View/AccessoriData/QComboBoxNewAccessori/cbmonth.h \
    View/AccessoriData/QComboBoxNewAccessori/cbrapportdaspettomonitor.h \
    View/AccessoriData/QComboBoxNewAccessori/cbrisoluzionemonitor.h \
    View/AccessoriData/QComboBoxNewAccessori/cbsensoremouse.h \
    View/AccessoriData/QComboBoxNewAccessori/cbtype.h \
    View/AccessoriData/cuffie_stampamodificadati.h \
    View/AccessoriData/monitor_stampamodificadati.h \
    View/AccessoriData/mouse_stampamodificadati.h \
    View/AccessoriData/newcuffielayout.h \
    View/AccessoriData/newmonitorlayout.h \
    View/AccessoriData/newmouselayout.h \
    View/AccessoriData/newtastieralayout.h \
    View/AccessoriData/newwebcamlayout.h \
    View/AccessoriData/tastiera_stampamodificadati.h \
    View/AccessoriData/webcam_stampamodificadati.h \
    View/LayoutView-QualityResearch/layoutquality.h \
    View/LayoutView-QualityResearch/layoutresearch.h \
    View/home.h \
    View/layoutdatiaccessorio.h \
    View/layoutinserisciarticolo.h \
    View/layoutlistaricercaaccessori.h \
    View/menubar.h \
    View/mwindow.h \
    View/notvalidexception.h \
    model.h

#Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin \

else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
