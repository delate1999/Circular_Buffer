#include <gtest/gtest.h>

extern "C"{
    #include "circular_buffer.h"
}

class circular_buffer_test: public ::testing::Test { 
public: 
    uint8_t* buf;
    size_t size; 
    circular_buffer_handler_t handler;

    void SetUp( ) { 
        size = 10;
        buf = (uint8_t*)malloc(10 * sizeof(uint8_t));
    }

    void TearDown( ) { 
       free(buf);
       circular_buffer_free(handler);
    }

};

TEST_F(circular_buffer_test, CheckIfFailedOnNullBuffer){
    buf = NULL;

    handler = circular_buffer_init(buf, size);
    EXPECT_EQ(handler, (circular_buffer_handler_t)NULL);
}

TEST_F(circular_buffer_test, CheckIfFailedOnZeroSize){
    size = 0; 

    handler = circular_buffer_init(buf, size);
    EXPECT_EQ(handler, (circular_buffer_handler_t)NULL);
}

TEST_F(circular_buffer_test, CheckIfEmptyOnInit){
    handler = circular_buffer_init(buf, size);
    EXPECT_EQ(circular_buffer_empty(handler), true);
}