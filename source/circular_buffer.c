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

static void circular_buffer_advance_pointers(circular_buffer_handler_t handler){
    if(handler->full){
        handler->tail++; 
        if(handler->tail == handler->max_size)
            handler->tail = 0;
    } 
    handler->head++;
    if(handler->head == handler->max_size)
            handler->head = 0;
    if((handler->head == handler->tail)) 
        handler->full = true; 
}

static void circular_buffer_retreat_pointers(circular_buffer_handler_t handler){
    handler->full = false; 

    handler->tail++;
    if(handler->tail == handler->max_size){
        handler->tail = 0; 
    }
}

bool circular_buffer_put(circular_buffer_handler_t handler, uint8_t data){
    if(handler == NULL || handler->buffer == NULL)
        return false; 

    handler->buffer[handler->head] = data; 

    circular_buffer_advance_pointers(handler);

    return true; 
}

bool circular_buffer_get(circular_buffer_handler_t handler, uint8_t* data){
    if(handler == NULL || handler->buffer == NULL)
        return false; 

    if(circular_buffer_empty(handler))
        return false;

    *data = handler->buffer[handler->tail]; 
    circular_buffer_retreat_pointers(handler);

    return true;
}
bool circular_buffer_empty(circular_buffer_handler_t handler){
    if(handler != NULL)
        return (!handler->full && (handler->head == handler->tail));
    else
        return false; 
}
bool circular_buffer_full(circular_buffer_handler_t handler){
    if(handler != NULL)
        return handler->full;
    else    
        return false; 
}