cmake_minimum_required(VERSION 2.8)

project(kr1)

#aux_source_directory(. SRC_LIST)

set(VECTOR_SRC task3.cpp List.cpp Matrix.cpp Node.cpp Num.cpp Temp.cpp AutoTest.cpp data.txt)
set(VECTOR_HDR List.h Matrix.h Node.h Num.h Temp.h)

#add_executable(${PROJECT_NAME} ${SRC_LIST})
#add_library(vector STATIC ${VECTOR_SRC} ${VECTOR_HDR})
add_executable(${PROJECT_NAME} ${VECTOR_SRC} ${VECTOR_HDR})

#target_link_libraries(${PROJECT_NAME} vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")