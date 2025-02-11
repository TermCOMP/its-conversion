cmake_minimum_required(VERSION 3.13)

project(its-conversion)

set(CMAKE_CXX_STANDARD 20)

# non-static build by default
option(STATIC:BOOL "static" ON)

if(${STATIC})
    message(STATUS "Configuring static build")
    set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
    set(BUILD_SHARED_LIBS OFF)
    add_link_options(-ldl -static)
    set(EXECUTABLE its-conversion-static)
else()
  set(CMAKE_FIND_LIBRARY_SUFFIXES ".so" ".a")
  message(STATUS "Configuring non-static build")
  set(EXECUTABLE its-conversion)
endif()

add_compile_options(-Wall -Wextra -pedantic -Wno-unused-parameter)

set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELEASE} -g")

message(STATUS "Build type: " ${CMAKE_BUILD_TYPE})
message(STATUS "Compiler flags:" ${CMAKE_CXX_COMPILE_FLAGS})
message(STATUS "Compiler cxx debug flags:" ${CMAKE_CXX_FLAGS_DEBUG})
message(STATUS "Compiler cxx release flags:" ${CMAKE_CXX_FLAGS_RELEASE})
message(STATUS "Compiler cxx relwithdebinfo flags:" ${CMAKE_CXX_FLAGS_RELWITHDEBINFO})
message(STATUS "Compiler cxx min size flags:" ${CMAKE_CXX_FLAGS_MINSIZEREL})
message(STATUS "Compiler cxx flags:" ${CMAKE_CXX_FLAGS})

find_library(ANTLR4 antlr4-runtime)
message(STATUS "antlr4: ${ANTLR4}")

add_executable(${EXECUTABLE} "")

target_sources(${EXECUTABLE}
    PRIVATE
        src/its.hpp
        src/its.cpp
        src/itsparser.cpp
        src/itsparser.hpp
        src/KoatParseVisitor.h
        src/KoatParseVisitor.cpp
        src/KoatVisitor.h
        src/KoatVisitor.cpp
        src/KoatListener.h
        src/KoatListener.cpp
        src/KoatLexer.cpp
        src/KoatLexer.h
        src/KoatParser.cpp
        src/KoatParser.h
        src/sexpresso.hpp
        src/sexpresso.cpp
        src/main.cpp
        src/ariparser.hpp
        src/ariparser.cpp
        src/parser.hpp
        src/parser.cpp
        src/util.hpp
        src/util.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE "/usr/include/antlr4-runtime")

target_link_libraries(${EXECUTABLE}
  ${ANTLR4}
  ${LINKER_OPTIONS}
)
