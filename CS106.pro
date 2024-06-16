QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adddefectdialog.cpp \
    addeditdefectmenudialog.cpp \
    addemployeedialog.cpp \
    addprojectdialog.cpp \
    adminmenudialog.cpp \
    assigndefectdialog.cpp \
    createreportdialog.cpp \
    editdefectdialog.cpp \
    employeemenudialog.cpp \
    logindialog.cpp \
    main.cpp \
    updateprioritydialog.cpp \
    updatestatusdialog.cpp

HEADERS += \
    adddefectdialog.h \
    addeditdefectmenudialog.h \
    addemployeedialog.h \
    addprojectdialog.h \
    adminmenudialog.h \
    assigndefectdialog.h \
    createreportdialog.h \
    editdefectdialog.h \
    employeemenudialog.h \
    logindialog.h \
    updateprioritydialog.h \
    updatestatusdialog.h

FORMS += \
    adddefectdialog.ui \
    addeditdefectmenudialog.ui \
    addemployeedialog.ui \
    addprojectdialog.ui \
    adminmenudialog.ui \
    assigndefectdialog.ui \
    createreportdialog.ui \
    editdefectdialog.ui \
    employeemenudialog.ui \
    logindialog.ui \
    updateprioritydialog.ui \
    updatestatusdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
