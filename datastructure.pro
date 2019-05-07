TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
    seqstack.c \
    linkstack.c \
    seqlist.c \
    circlelist.c \
    dlinklist.c \
    seqqueue.c \
    linkqueue.c \
    linklist.c

HEADERS += \
    seqstack.h \
    linkstack.h \
    seqlist.h \
    circlelist.h \
    seqqueue.h \
    linkqueue.h \
    dlinklist.h \
    linklist.h

DISTFILES +=
