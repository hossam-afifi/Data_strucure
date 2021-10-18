/*
 * FIFO.c
 *
 *  Created on: Sep 17, 2021
 *      Author: amagd
 */


#include "FIFO.h"



FIFO_status FIFO_init(FIFO_buf*fifo,element_type* buf, uint32_t length){
	if(buf == 0)
		return FIFO_NULL;
	fifo->base=buf;
	fifo->head=buf;
	fifo->tail=buf;
	fifo->length=length;
	fifo->count=0;

	return FIFO_NO_ERROR;

}

FIFO_status FIFO_enqueue(FIFO_buf*fifo,element_type item){

	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(FIFO_full(fifo) == FIFO_FULL)
		return FIFO_FULL;
	*(fifo->head) = item;
	fifo->count++;
	if(fifo->head == (fifo->base + (fifo->length * sizeof(element_type))))

		fifo->head = fifo->base;
	else
		fifo->head++;

	return FIFO_NO_ERROR;

}
FIFO_status FIFO_dequeue(FIFO_buf*fifo,element_type* item){
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(fifo->count == 0)
		return FIFO_EMPTY;
	*item = *(fifo->tail) ;
	fifo->count--;
	if(fifo->tail == (fifo->base + (fifo->length *sizeof(element_type))))
		fifo->tail = fifo->base;
	else
		fifo->tail++;

	return FIFO_NO_ERROR;

}
FIFO_status FIFO_full(FIFO_buf*fifo){
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(fifo->count == fifo->length)
		return FIFO_FULL;
	return FIFO_NO_ERROR;
}
void FIFO_print(FIFO_buf*fifo){

	element_type *temp;
	if(fifo->count == 0)
		printf("first is empty\n");
	else
		temp= fifo->tail;
	printf("\n=======fifo_print======\n");
	for(int i=0;i<fifo->count;i++){
		printf("\t%x\n",*temp);
		temp++;
	}
	printf("#######################\n");
}
