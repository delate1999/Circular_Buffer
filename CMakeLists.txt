cmake_minimum_required(VERSION 3.8)

set(THIS CircularBufferExample)
set(THIS_LIB CircularBufferLib)
set(SOURCE ./source)
set(INCLUDE ./include)

project(${THIS} 
        VERSION     0.1
        LANGUAGES   C CXX
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

set(SOURCES
    ${SOURCE}/circular_buffer.c
)

set(HEADERS
    ${INCLUDE}/circular_buffer.h
)

include_directories(${INCLUDE})

add_library(${THIS_LIB} ${SOURCES} ${HEADERS})

add_executable(${THIS} ${SOURCE}/main.c)

target_link_libraries(${THIS} PRIVATE ${THIS_LIB})