project(PascalCompiler)
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/antlr_lib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/antlr_gen/src)

file(GLOB ANTLR_GEN_EXES
     "${CMAKE_CURRENT_SOURCE_DIR}/antlr_gen/src/*.cpp"
)

file(GLOB libantlrcpp_SRC
  "${PROJECT_SOURCE_DIR}/antlr_lib/*.cpp"
  "${PROJECT_SOURCE_DIR}/antlr_lib/*/*.cpp"
  "${PROJECT_SOURCE_DIR}/antlr_lib/*/*/*.cpp"
)

#Put the cpp for the main exe here.
add_executable(main
  src/ExprMain.cpp
  ${ANTLR_GEN_EXES}
)

add_library(antlr4_static STATIC ${libantlrcpp_SRC})
target_link_libraries(main PRIVATE antlr4_static)
set_property(TARGET main PROPERTY CXX_STANDARD 17)
