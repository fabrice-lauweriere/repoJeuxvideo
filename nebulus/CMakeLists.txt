cmake_minimum_required(VERSION 2.6)
project(nebulus)

OPTION(USE_LIBSL_BINARIES  "Use LibSL binaries from this package" ON)

IF (USE_LIBSL_BINARIES)
SET(LibSL_DIR        ${CMAKE_SOURCE_DIR}/../LibSL-bin-win32)
ENDIF (USE_LIBSL_BINARIES)

FIND_PACKAGE(LibSL)
INCLUDE_DIRECTORIES( ${LIBSL_INCLUDE_DIR} )
LINK_DIRECTORIES( ${LIBSL_BINARY_DIR} )
ADD_DEFINITIONS(-DUSE_GLUX)

ADD_SUBDIRECTORY(common)
INCLUDE_DIRECTORIES(common)

AUTO_BIND_SHADERS( shader_sh )

ADD_EXECUTABLE(nebulus main.cpp controls.cpp controls.h enemies.cpp enemies.h graphics.cpp graphics.h light.cpp light.h personnage.cpp personnage.h constants.h shader_sh.h shader_sh.fp shader_sh.vp)
TARGET_LINK_LIBRARIES(nebulus common ${LIBSL_LIBRARIES} ${LIBSL_GL_LIBRARIES})
