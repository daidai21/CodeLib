# set min support version
cmake_minimum_required(VERSION 3.7)


# project name
project(template)

# set env var
set(INC_DIR include/)  # header file
set(LINK_DIR lib/)  # link lib
SET(SRC_LIST main.c)  # source code


SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# add .h file
INCLUDE_DIRECTORIES(${INC_DIR})
# add .so, .dll file
LINK_LIBRARIES(${LINK_DIR})
# add lib
TARGET_LINK_LIBRARIES()

ADD_SUBDIRECTORY(lib)


#
include(ExternalProject)

ExternalProject_Add()


MESSAGE(STATUS "")

# gererate can to run file
ADD_EXECUTABLE(hello ${SRC_LIST})
ADD_LIBRARY(template ${SRC_LIST})
ADD_LIBRARY(template SHARED ${SRC_LIST})
ADD_LIBRARY(template STATIC ${SRC_LIST})
SET_TARGET_PROPERTIES()


# install
INSTALL()


