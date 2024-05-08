cmake_minimum_required(VERSION 3.8)

set(This circular_buffer_test)

set(Sources
    circular_buffer_test.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    CircularBufferLib
)

add_test(
    NAME ${This}
    COMMAND ${This}
)