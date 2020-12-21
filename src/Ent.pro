TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    appendstrings.cpp \
    assignvar.cpp \
    block.cpp \
    call.cpp \
    ent_string.cpp \
    expr.cpp \
    exprstmt.cpp \
    function.cpp \
    main.cpp \
    print.cpp \
    reassignvar.cpp \
    readvar.cpp \
    return.cpp \
    runtime.cpp \
    stmt.cpp \
    void.cpp

HEADERS += \
    appendstrings.h \
    assignvar.h \
    block.h \
    call.h \
    ent.h \
    ent_string.h \
    expr.h \
    exprstmt.h \
    function.h \
    print.h \
    reassignvar.h \
    readvar.h \
    return.h \
    runtime.h \
    stmt.h \
    void.h
