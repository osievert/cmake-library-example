cmake_minimum_required(VERSION 3.16)

project(example LANGUAGES CXX)

add_library(static STATIC static.cpp)
target_include_directories(static PRIVATE .)
set_target_properties(static PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_library(dynamic SHARED dynamic.cpp)
target_include_directories(dynamic PRIVATE .)
target_link_libraries(dynamic PRIVATE static)

add_executable(app main.cpp)
target_include_directories(app PRIVATE .)
target_link_libraries(app PRIVATE dynamic)
set_target_properties(app PROPERTIES INSTALL_RPATH @executable_path/../lib)

if (CMAKE_GENERATOR STREQUAL Xcode)
    set_target_properties(static dynamic app PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++17")
else()
    set_target_properties(static dynamic app PROPERTIES CXX_STANDARD 17)
endif()

install(TARGETS dynamic DESTINATION "lib")
install(TARGETS app DESTINATION "bin")

