#include <stdlib.h>
#include <stdint.h>
#include "circular_buffer.h"

struct circular_buffer_t {
    uint8_t* buffer;
    uint8_t head; 
    uint8_t tail; 
    size_t max_size; 
    uint8_t full; 
};

circular_buffer_handler_t circular_buffer_init(uint8_t buffer, size_t size){

}
void circular_buffer_free(circular_buffer_handler_t handler){

}
uint8_t circular_buffer_put(circular_buffer_handler_t handler, uint8_t data){

}
uint8_t circular_buffer_get(circular_buffer_handler_t handler, uint8_t* data){

}
uint8_t circular_buffer_empty(circular_buffer_handler_t handler){

}
uint8_t circular_buffer_full(circular_buffer_handler_t handler){

}