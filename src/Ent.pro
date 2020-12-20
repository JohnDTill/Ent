TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    appendstrings.cpp \
    assignvar.cpp \
    block.cpp \
    ent_string.cpp \
    expr.cpp \
    main.cpp \
    print.cpp \
    reassignvar.cpp \
    readvar.cpp \
    runtime.cpp \
    stmt.cpp

HEADERS += \
    appendstrings.h \
    assignvar.h \
    block.h \
    ent.h \
    ent_string.h \
    expr.h \
    print.h \
    reassignvar.h \
    readvar.h \
    runtime.h \
    stmt.h
