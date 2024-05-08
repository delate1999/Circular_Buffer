#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>
#include <stdlib.h>

typedef struct circular_buffer_t circular_buffer_t;    /* Opaque */
typedef circular_buffer_t* circular_buffer_handler_t;

circular_buffer_handler_t circular_buffer_init(uint8_t buffer, size_t size);
void circular_buffer_free(circular_buffer_handler_t handler);
uint8_t circular_buffer_put(circular_buffer_handler_t handler, uint8_t data);
uint8_t circular_buffer_get(circular_buffer_handler_t handler, uint8_t* data);
uint8_t circular_buffer_empty(circular_buffer_handler_t handler);
uint8_t circular_buffer_full(circular_buffer_handler_t handler);

#endif /* CIRCULAR_BUFFER_H*/