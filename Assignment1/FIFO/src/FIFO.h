/*
 * FIFO.h
 *
 *  Created on: Sep 17, 2021
 *      Author: amagd
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdint.h"
#include "stdio.h"

#define element_type uint8_t
#define uint32_t unsigned int
#define width	5

element_type var_buffer[5];
typedef struct {

uint32_t length;
uint32_t count;
element_type* base;
element_type* head;
element_type* tail;
}FIFO_buf;

typedef enum {
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL
}FIFO_status;



//FIFO APIs

FIFO_status FIFO_init(FIFO_buf*fifo,element_type* buf, uint32_t length);
FIFO_status FIFO_enqueue(FIFO_buf*fifo,element_type item);
FIFO_status FIFO_dequeue(FIFO_buf*fifo,element_type* item);
FIFO_status FIFO_full(FIFO_buf*fifo);
void FIFO_print(FIFO_buf*fifo);

#endif /* FIFO_H_ */
