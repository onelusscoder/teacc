#
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
## Project name
project(teacc VERSION 0.1.0 LANGUAGES CXX)
set(FrameWorkName "tea++")
message ("**************** " ${FrameWorkName} " Master Project ********************")
#
option(BUILD_UTILS "Enable building the tea++ common utilities (utils) library" ON)
option(BUILD_TEALOG "Enable building the TEALOG ( tea_log ) utility library" OFF)
option(BUILD_VAULT "Enable building the vault/[SQLite,...] Database support  library" OFF)
option(BUILD_TEASCRIPT "Enable building the tea++ [teascript])  interpreter library" OFF)
option(BUILD_APPBOOK "Enable building the application book library" OFF)
option(BUILD_DIAGNOSTICS "Enable building the diagnostics Library which provides a growing general purpose messaging [return]codes repository" ON)
#option(BUILD_TAA "Enable building the Terminal Application Api" OFF)
option(BUILD_TESTS "Build the tests application based on the Diagnostics framework" OFF)

#

SET(FRAMEWORK_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

message("Framework Root path:" ${FRAMEWORK_ROOT})
if(BUILD_UTILS)
    SET(UTILS_INCLUDE_DIR ${FRAMEWORK_ROOT}/utils/include)
    add_subdirectory(utils)
endif()

if(BUILD_TEALOG)
    SET(TEALOG_INCLUDE_DIR ${FRAMEWORK_ROOT}/tealog/include)
    add_subdirectory(tealog)
endif()


if(BUILD_VAULT)
    SET(VAULT_INCLUDE_DIR ${FRAMEWORK_ROOT}/vault/include)
    add_subdirectory(vault)
endif()
#
if(BUILD_TEASCRIPT)
    SET(TEASCRIPT_INCLUDE_DIR ${FRAMEWORK_ROOT}/teascript/include)
    add_subdirectory(teascript)
endif()
#

if(BUILD_DIAGNOSTICS)
    SET(DIAGNOSTICS_INCLUDE_DIR ${FRAMEWORK_ROOT}/diagnostics/include)
    add_subdirectory(diagnostics)
endif()
#
#if(BUILD_TAA)
#    SET(TerminalAppApi_INCLUDE_DIR ${LSC_ROOT}/TerminalAppApi/include)
#    add_subdirectory(TerminalAppApi)
#endif()
#
#
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
#
if(BUILD_APPBOOK)
   SET(APPBOOK_INCLUDE_DIR ${FRAMEWORK_ROOT}/application_book/include)
   add_subdirectory(application_book)
endif()
#
#
#message ("Project SourceDir:" ${PROJECT_SOURCE_DIR})
#
#
#IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
#	EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
#			${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
#			)
#ENDIF()
#
#
## uninstall target
#if(NOT TARGET uninstall)
#  configure_file(
#    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
#    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
#    IMMEDIATE @ONLY)
#
#  add_custom_target(uninstall
#    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
#endif()
