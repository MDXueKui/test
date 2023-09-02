cmake_minimum_required (VERSION 2.8)

set(CMAKE_C_FLAGS "-std=c99")

project (cjson_test)

aux_source_directory(. DIR_SRCS)

LINK_LIBRARIES(m)

add_executable(cjson_test ${DIR_SRCS})