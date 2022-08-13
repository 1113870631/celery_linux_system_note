cmake_minimum_required(VERSION 3.0.0)
project(TCP_CLINT VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(TCP_CLINT main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
