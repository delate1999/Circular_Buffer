cmake_minimum_required(VERSION 3.8)

set(THIS CircularBufferExample)
set(THIS_LIB CircularBufferLib)

project(${THIS} 
        VERSION     0.1
        LANGUAGES   C CXX
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

set(SOURCES
    circular_buffer.c
)

set(HEADERS
    circular_buffer.h
)

add_library(${THIS_LIB} ${SOURCES} ${HEADERS})

add_executable(${THIS} main.c)

target_link_libraries(${THIS} PRIVATE ${THIS_LIB})