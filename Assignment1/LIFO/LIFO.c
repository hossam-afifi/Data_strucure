/*
 * LIFO.c
 *
 *  Created on: Sep 4, 2021
 *      Author: amagd
 */


#include "LIFO.h"




LIFO_status LIFO_init(LIFO_bus_t *LIFO_buf ,uinit_32 *buf ,uinit_32 length){

	if(buf == 0)
		return LIFO_NUL;
	LIFO_buf->base = buf;
	LIFO_buf->head = buf;
	LIFO_buf->lenght = length;
	LIFO_buf->count =   0;
	return LIFO_NO_ERROR;
}

LIFO_status LIFO_Push_item(LIFO_bus_t *LIFO_buf ,uinit_32 item){
	if( !LIFO_buf->head ||!LIFO_buf->base)
		return LIFO_NUL;
	if(LIFO_buf->count == LIFO_buf->lenght)
		return LIFO_FULL;
	*(LIFO_buf->head) = item;
	LIFO_buf->count++;
	LIFO_buf->head++;
	return LIFO_NO_ERROR;

}
LIFO_status LIFO_Pull_item(LIFO_bus_t *LIFO_buf,uinit_32 *item){
	if( !LIFO_buf->head ||!LIFO_buf->base)
		return LIFO_NUL;
	if(LIFO_buf->count == 0)
		return LIFO_EMPTY;
	LIFO_buf->head--;
	*(item) = *(LIFO_buf->head) ;
	LIFO_buf->count--;
	return LIFO_NO_ERROR;
}











//initialization LIFO STACK

LIFO_status LIFO_init(LIFO_bus_t *LIFO_buf ,uinit_32 *buf ,uinit_32 length){

	if(buf == 0)
		return LIFO_NUL;
	LIFO_buf->base = buf;
	LIFO_buf->head = buf;
	LIFO_buf->lenght = length;
	LIFO_buf->count =   0;
	return LIFO_NO_ERROR;
}

LIFO_status LIFO_Push_item(LIFO_bus_t *LIFO_buf ,uinit_32 item){
	if( !LIFO_buf->head ||!LIFO_buf->base)
		return LIFO_NUL;
	if(LIFO_buf->count == LIFO_buf->lenght)
		return LIFO_FULL;
	*(LIFO_buf->head) = item;
	LIFO_buf->count++;
	LIFO_buf->head++;
	return LIFO_NO_ERROR;

}
LIFO_status LIFO_Pull_item(LIFO_bus_t *LIFO_buf,uinit_32 *item){
	if( !LIFO_buf->head ||!LIFO_buf->base)
		return LIFO_NUL;
	if(LIFO_buf->count == 0)
		return LIFO_EMPTY;
	LIFO_buf->head--;
	*(item) = *(LIFO_buf->head) ;
	LIFO_buf->count--;
	return LIFO_NO_ERROR;
}
/*
LIFO_status LIFO_IS_Empty(LIFO_bus_t *LIFO_buf){

}
LIFO_status LIFO_IS_Full(LIFO_bus_t *LIFO_buf){

}


*/
