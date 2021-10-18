/*
 * LIFO.h
 *
 *  Created on: Sep 4, 2021
 *      Author: amagd
 */

#ifndef LIFO_H_
#define LIFO_H_



typedef unsigned int    uinit_32;

typedef struct {

	uinit_32 lenght;
	uinit_32	count;
	uinit_32	*base;
	uinit_32	*head;
}LIFO_bus_object;

typedef enum {
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NUL
}LIFO_status;

// API Function LIFO object


LIFO_status LIFO_init(LIFO_bus_t *LIFO_buf ,uinit_32 *buf ,uinit_32 length);
LIFO_status LIFO_Push_item(LIFO_bus_t *LIFO_buf ,uinit_32 item);
LIFO_status LIFO_Pull_item(LIFO_bus_t *LIFO_buf,uinit_32 *item);
LIFO_status LIFO_IS_Empty(LIFO_bus_t *LIFO_buf);
LIFO_status LIFO_IS_Full(LIFO_bus_t *LIFO_buf);


typedef struct {

	uinit_32 lenght;
	uinit_32	count;
	uinit_32	*base;
	uinit_32	*head;
}LIFO_bus_t;

typedef enum {
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NUL
}LIFO_status;

// API Function LIFO


LIFO_status LIFO_init(LIFO_bus_t *LIFO_buf ,uinit_32 *buf ,uinit_32 length);
LIFO_status LIFO_Push_item(LIFO_bus_t *LIFO_buf ,uinit_32 item);
LIFO_status LIFO_Pull_item(LIFO_bus_t *LIFO_buf,uinit_32 *item);
LIFO_status LIFO_IS_Empty(LIFO_bus_t *LIFO_buf);
LIFO_status LIFO_IS_Full(LIFO_bus_t *LIFO_buf);

#endif /* LIFO_H_ */
