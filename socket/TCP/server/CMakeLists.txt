cmake_minimum_required(VERSION 3.0.0)
project(TCP_test VERSION 0.1.0)

include(CTest)
enable_testing()


add_executable(TCP_test main.c)

target_link_libraries(TCP_test pthread)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
