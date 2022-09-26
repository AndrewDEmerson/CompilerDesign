project(myThing)
cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/antlr_lib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/antlr_gen)

file(GLOB ANTLR_GEN_EXES
     "${CMAKE_CURRENT_SOURCE_DIR}/antlr_gen/*.cpp"
)

file(GLOB libantlrcpp_SRC
  "${PROJECT_SOURCE_DIR}/antlr_lib/*.cpp"
  "${PROJECT_SOURCE_DIR}/antlr_lib/atn/*.cpp"
  "${PROJECT_SOURCE_DIR}/antlr_lib/dfa/*.cpp"
  "${PROJECT_SOURCE_DIR}/antlr_lib/internal/*.cpp"
  "${PROJECT_SOURCE_DIR}/antlr_lib/misc/*.cpp"
  "${PROJECT_SOURCE_DIR}/antlr_lib/support/*.cpp"
  "${PROJECT_SOURCE_DIR}/antlr_lib/tree/*.cpp"
  "${PROJECT_SOURCE_DIR}/antlr_lib/tree/pattern/*.cpp"
  "${PROJECT_SOURCE_DIR}/antlr_lib/tree/xpath/*.cpp"
)

#Put the cpp for the main exe here.
add_executable(main
  src/ExprMain.cpp
  ${ANTLR_GEN_EXES}
)

add_library(antlr4_static STATIC ${libantlrcpp_SRC})
target_link_libraries(main PRIVATE antlr4_static)
set_property(TARGET main PROPERTY CXX_STANDARD 20)
