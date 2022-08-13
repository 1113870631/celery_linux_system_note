cmake_minimum_required(VERSION 3.0.0)
project(core_test VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(core_test main.c relayer.c)
find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
  target_compile_options(my_app PUBLIC "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(core_test "${CMAKE_THREAD_LIBS_INIT}")
endif()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
