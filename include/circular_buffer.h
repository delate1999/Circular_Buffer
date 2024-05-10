#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct circular_buffer_t circular_buffer_t;    /* Opaque */
typedef circular_buffer_t* circular_buffer_handler_t;

circular_buffer_handler_t circular_buffer_init(uint8_t* , size_t );
void circular_buffer_free(circular_buffer_handler_t );
bool circular_buffer_put(circular_buffer_handler_t , uint8_t );
bool circular_buffer_get(circular_buffer_handler_t , uint8_t* );
bool circular_buffer_empty(circular_buffer_handler_t );
bool circular_buffer_full(circular_buffer_handler_t );

#endif /* CIRCULAR_BUFFER_H*/