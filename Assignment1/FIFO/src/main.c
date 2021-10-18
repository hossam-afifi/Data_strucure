/*
 ============================================================================
 Name        : FIFO
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "stdint.h"
#include "stdio.h"
#include "FIFO.h"


int main(void) {
	element_type temp=0;
	FIFO_buf fifo_uart;

	if(FIFO_init(&fifo_uart,var_buffer,5) == FIFO_NO_ERROR)
		printf("FIFO_init ------ done\n");
	else
		printf("FIFO_init ----- failed\n");
	for(int i=0;i<7;i++) {
		printf("FIFO_enqueue(%x)\n",i);
		if(FIFO_enqueue(&fifo_uart,i) == FIFO_NO_ERROR)
			printf("FIFO_enqueue ----- done\n");
		else
			printf("FIFO_enqueue ----- failed\n");
	}
	FIFO_print(&fifo_uart);
		if(FIFO_dequeue(&fifo_uart,&temp) == FIFO_NO_ERROR)
			printf("FIFO_dequeue ----- done\n");
		else
			printf("FIFO_dequeue ----- failed\n");

		FIFO_print(&fifo_uart);

		return 0;
	}
