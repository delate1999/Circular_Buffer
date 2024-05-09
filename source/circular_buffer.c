#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "circular_buffer.h"

struct circular_buffer_t {
    uint8_t* buffer;
    uint8_t head; 
    uint8_t tail; 
    size_t max_size; 
    uint8_t full; 
};

circular_buffer_handler_t circular_buffer_init(uint8_t* buffer, size_t size){
    circular_buffer_handler_t handler;

    if(buffer == NULL || size == 0){
        return NULL; 
    }

    handler = malloc(sizeof(circular_buffer_handler_t));
    handler->buffer = buffer;
    handler->max_size = size;
    handler->full = false; 
    handler->head = handler->tail = 0;  

    return handler; 
}
void circular_buffer_free(circular_buffer_handler_t handler){
    if(handler != NULL){
        free(handler);
        handler = NULL; 
    }
}
uint8_t circular_buffer_put(circular_buffer_handler_t handler, uint8_t data){

}
uint8_t circular_buffer_get(circular_buffer_handler_t handler, uint8_t* data){

}
uint8_t circular_buffer_empty(circular_buffer_handler_t handler){
    return (!handler->full && (handler->head == handler->tail));
}
uint8_t circular_buffer_full(circular_buffer_handler_t handler){

}