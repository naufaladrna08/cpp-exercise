cmake_minimum_required(VERSION 3.0.0)
project(CPP_STL VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(word-frequency-counter)
add_subdirectory(task-scheduler)
add_subdirectory(spell-checker)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
