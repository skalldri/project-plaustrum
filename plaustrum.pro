TEMPLATE = app
TARGET = plaustrum

CONFIG += qt warn_on debug_and_release cascades
LIBS += -lbbdata -lbbsystem -lbbcascadesmaps -lQtLocationSubset

INCLUDEPATH += ../src
SOURCES += ../src/*.cpp ../src/Stops/*.cpp ../src/Map/*.cpp ../src/DataTypes/*.cpp
HEADERS += ../src/*.hpp ../src/*.h ../src/Stops/*.hpp ../src/Map/*.hpp ../src/DataTypes/*.hpp

lupdate_inclusion {
    SOURCES += ../assets/*.qml
}

device {
    CONFIG(release, debug|release) {
        DESTDIR = o.le-v7
        TEMPLATE = lib
        QMAKE_CXXFLAGS_RELEASE += -fvisibility=hidden -mthumb
    }
    CONFIG(debug, debug|release) {
        DESTDIR = o.le-v7-g
    }
}

simulator {
    CONFIG(release, debug|release) {
        DESTDIR = o
    }
    CONFIG(debug, debug|release) {
        DESTDIR = o-g
    }
}

OBJECTS_DIR = $${DESTDIR}/.obj
MOC_DIR = $${DESTDIR}/.moc
RCC_DIR = $${DESTDIR}/.rcc
UI_DIR = $${DESTDIR}/.ui

suredelete.target = sureclean
suredelete.commands = $(DEL_FILE) $${MOC_DIR}/*; $(DEL_FILE) $${RCC_DIR}/*; $(DEL_FILE) $${UI_DIR}/*
suredelete.depends = distclean

QMAKE_EXTRA_TARGETS += suredelete

