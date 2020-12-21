TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    accessarrayelement.cpp \
    accessvar.cpp \
    appendstrings.cpp \
    array.cpp \
    assignvar.cpp \
    block.cpp \
    call.cpp \
    ent_string.cpp \
    expr.cpp \
    exprstmt.cpp \
    function.cpp \
    lvalue.cpp \
    main.cpp \
    print.cpp \
    reassignlvalue.cpp \
    reassignvar.cpp \
    readvar.cpp \
    return.cpp \
    runtime.cpp \
    stmt.cpp \
    void.cpp

HEADERS += \
    accessarrayelement.h \
    accessvar.h \
    appendstrings.h \
    array.h \
    assignvar.h \
    block.h \
    call.h \
    ent.h \
    ent_string.h \
    expr.h \
    exprstmt.h \
    function.h \
    lvalue.h \
    print.h \
    reassignlvalue.h \
    reassignvar.h \
    readvar.h \
    return.h \
    runtime.h \
    stmt.h \
    void.h
