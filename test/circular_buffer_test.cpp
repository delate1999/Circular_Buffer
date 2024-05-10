#include <gtest/gtest.h>

#define BUFFER_SIZE     10

extern "C"{
    #include "circular_buffer.h"
}

class circular_buffer_test: public ::testing::Test { 
public: 
    uint8_t* buf = NULL;
    size_t size; 
    circular_buffer_handler_t handler = NULL;

    void SetUp( ) { 
        size = BUFFER_SIZE;
        buf = (uint8_t*)malloc(BUFFER_SIZE * sizeof(uint8_t));
    }

    void TearDown( ) { 
       circular_buffer_free(handler);
       free(buf);
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

TEST_F(circular_buffer_test, CheckIfFailOnNullHandlerFull){
    EXPECT_EQ(circular_buffer_full(NULL), false);
}

TEST_F(circular_buffer_test, CheckIfFailOnNullHandlerEmpty){
    EXPECT_EQ(circular_buffer_empty(NULL), false);
}

TEST_F(circular_buffer_test, CheckIfGetFailsOnNullPtr){
    uint8_t data = 0x00; 
    EXPECT_EQ(circular_buffer_get(NULL, &data), false);
}

TEST_F(circular_buffer_test, CheckIfPutFailsOnNullPtr){
    uint8_t data = 0xFF; 
    EXPECT_EQ(circular_buffer_put(NULL, data), false);
}

TEST_F(circular_buffer_test, CheckIfPutsAndGetsTheSameData){
    uint8_t data_put = 0xFF;
    uint8_t data_get = 0x00;

    handler = circular_buffer_init(buf, size);
    EXPECT_EQ(circular_buffer_put(handler, data_put), true);
    EXPECT_EQ(circular_buffer_get(handler, &data_get), true);
    EXPECT_EQ(data_put, data_get);
}

TEST_F(circular_buffer_test, CheckIfPutsAndGetsTheSameDataMultipleTries){
    uint8_t data_put[3] = {0x01, 0x02, 0x03};
    uint8_t data_get[3] = {0x00};

    handler = circular_buffer_init(buf, size);
    circular_buffer_put(handler, data_put[0]);
    circular_buffer_put(handler, data_put[1]);
    circular_buffer_put(handler, data_put[2]);
    circular_buffer_get(handler, &data_get[0]);
    circular_buffer_get(handler, &data_get[1]);
    circular_buffer_get(handler, &data_get[2]);

    EXPECT_EQ(data_put[0], data_get[0]);
    EXPECT_EQ(data_put[1], data_get[1]);
    EXPECT_EQ(data_put[2], data_get[2]);
}
