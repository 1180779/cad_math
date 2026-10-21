cmake_minimum_required(VERSION 4.1)
project(cad_math LANGUAGES CXX)

add_library(cad_math INTERFACE)
add_library(cad_math::cad_math ALIAS cad_math)

target_compile_features(cad_math INTERFACE cxx_std_20)
target_include_directories(cad_math INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include>
        $<INSTALL_INTERFACE:include>
)


file(GLOB_RECURSE CAD_MATH_HEADERS CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/include/cad_math/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/include/cad_math/*.hxx"
)

target_sources(cad_math PUBLIC
        FILE_SET HEADERS
        BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/src/include"
        FILES ${CAD_MATH_HEADERS}
)
