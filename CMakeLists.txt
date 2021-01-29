#
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
## Project name
project(teacc VERSION 0.1.0 LANGUAGES CXX)
set(FrameWorkName "tea++")
message ("**************** " ${FrameWorkName} " Master Project ********************")
#
option(BUILD_UTILS "Enable building the Utilities (utils) library" ON)
option(BUILD_TEALOG "Enable building the TEALOG ( tea_log ) utility library" ON)
#option(BUILD_VAULT "Enable building the Vault/[SQLite,...] Database support  Library" ON)
#option(BUILD_SCRIPTURE "Enable building the Scripture interpreter Library" ON)
#option(BUILD_APPBOOK "Enable building the AppBook Library" ON)
option(BUILD_DIAGNOSTICS "Enable building the Diagnostics Library" ON)
#option(BUILD_TAA "Enable building the Terminal Application Api" OFF)
#
SET(FRAMEWORK_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

message("Framework Root path:" ${FRAMEWORK_ROOT})
if(BUILD_UTILS)
    SET(UTILS_INCLUDE_DIR ${FRAMEWORK_ROOT}/utils/include)
    add_subdirectory(utils)
endif()

if(BUILD_TEALOG)
    SET(TEALOG_INCLUDE_DIR ${FRAMEWORK_ROOT}/logger/include)
    add_subdirectory(logger)
endif()


#if(BUILD_VAULT)
#    SET(VAULT_INCLUDE_DIR ${LSC_ROOT}/Vault/include)
#    add_subdirectory(Vault)
#endif()
#
#if(BUILD_SCRIPTURE)
#    SET(SCRIPTURE_INCLUDE_DIR ${LSC_ROOT}/Scripture/include)
#    add_subdirectory(Scripture)
#endif()
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
#if(BUILD_APPBOOK)
#    SET(APPBOOK_INCLUDE_DIR ${LSC_ROOT}/AppBook/include)
#    add_subdirectory(AppBook)
#endif()
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
