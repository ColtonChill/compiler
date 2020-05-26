
cmake_minimum_required(VERSION 3.10)
project(compile)

find_package(BISON)
find_package(FLEX)

bison_target(Parser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
flex_target(Scanner scanner.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)
add_flex_bison_dependency(Scanner Parser)


set(EXTRA_COMPILE_FLAGS "-g3 -std=c++14")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EXTRA_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")

set(compiler_srcs
  main.cpp
  RegisterPool.hpp
  RegisterPool.cpp
  symbol_table.hpp
  symbol_table.cpp
  OffSets.hpp
  OffSets.cpp
  StrTable.hpp
  StrTable.cpp
  ${BISON_Parser_OUTPUTS}
  ${FLEX_Scanner_OUTPUTS}
)
source_group("compile" FILES ${compiler_srcs})

add_executable(compile ${compiler_srcs})
target_link_libraries(compile ${FLEX_LIBRARIES} ${BISON_LIBRARIES})
target_include_directories(compile PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

