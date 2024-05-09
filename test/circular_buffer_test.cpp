#include <gtest/gtest.h>

extern "C"{
    #include "circular_buffer.h"
}

TEST(circular_buffer_test, CheckIfFailedOnNullBuffer){
    uint8_t* buf = NULL;
    const size_t size = 10; 
    circular_buffer_handler_t handler; 

    handler = circular_buffer_init(buf, size);
    EXPECT_EQ(handler, (circular_buffer_handler_t)NULL);

    circular_buffer_free(handler);
}

TEST(circular_buffer_test, CheckIfFailedOnZeroSize){
    uint8_t* buf = NULL;
    const size_t size = 0; 
    circular_buffer_handler_t handler; 
    buf = (uint8_t*)malloc(10 * sizeof(uint8_t));

    handler = circular_buffer_init(buf, size);
    EXPECT_EQ(handler, (circular_buffer_handler_t)NULL);

    free(buf);
    circular_buffer_free(handler);
}

TEST(circular_buffer_test, CheckIfEmptyOnInit){
    uint8_t* buf = NULL;
    const size_t size = 10; 
    circular_buffer_handler_t handler; 
    buf = (uint8_t*)malloc(10 * sizeof(uint8_t));

    handler = circular_buffer_init(buf, size);

    EXPECT_EQ(circular_buffer_empty(handler), true);

    free(buf);
    circular_buffer_free(handler);
}