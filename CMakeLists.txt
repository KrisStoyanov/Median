cmake_minimum_required(VERSION 3.18)

project("Median")

add_executable("${PROJECT_NAME}" "Main.cpp")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)

install(FILES "Main.cpp" DESTINATION src)

enable_testing()