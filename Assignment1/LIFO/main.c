/*
 * main.c
 *
 *  Created on: Sep 4, 2021
 *      Author: amagd
 */

#include "stdlib.h"
#include "stdio.h"
#include "LIFO.h"

typedef unsigned char uint8;

typedef struct Sstudent {
	uint8 sname;
	uint8 subject;
	uinit_32 id;
	uinit_32 GPA;

} sData;

sData sdata[5];

int main (){
	//static allocation
	//uinit_32 buffer_1[5];
	uinit_32 temp=0;
	//dynamic allocation
	uinit_32 *buffer_2 = (uinit_32*)malloc(7*sizeof(uinit_32));
	LIFO_bus_t Uart_lifo,I2C_lifo;
	LIFO_init(&Uart_lifo, sdata, 5);

	for (int i = 0; i < 5; i++) {
		printf("%d-enter name student:",i+1);
		gets(sdata[i].sname);
		printf("\n enter name subject:");
		gets(sdata[i].subject);
		printf("\n enter name id:");
		fflush(stdout); fflush(stdin);
		scanf("%d",sdata[i].id);
		printf("\n enter name GPA:");
		scanf("%d",sdata[i].GPA);
		printf("################################\n");

	}

	for (int i = 0; i < 8; i++) {
		if(LIFO_Push_item(&Uart_lifo,i) == LIFO_NO_ERROR)
			printf("uart_lifo push(%d):%d\n",i,i);
		else
			printf("LIFO_Push_item(%d) is Failed\n",i);
	}
	printf("################################\n");
	for (int i = 0; i < 7; i++) {
		if(LIFO_Pull_item(&Uart_lifo,&temp) == LIFO_NO_ERROR)
			printf("Uart_lifo pull:%d\n",temp);
		else
			printf("LIFO_Pull_item(%d) is Failed\n",i);
	}
	printf("################################\n");
	//implementation dynamic allocation
	LIFO_init(&I2C_lifo,buffer_2,7);
	for (int i = 0; i < 8; i++) {
		if(LIFO_Push_item(&I2C_lifo,i) == LIFO_NO_ERROR)
			printf("I2C_lifo push(%d):%d\n",i,i);
		else
			printf("LIFO_Push_item(%d) is Failed\n",i);
	}
	printf("################################\n");
	for (int i = 0; i < 8; i++) {
		if(LIFO_Pull_item(&I2C_lifo,&temp) == LIFO_NO_ERROR)
			printf("I2C_lifo pull:%d\n",temp);
		else
			printf("LIFO_Pull_item(%d) is Failed\n",i);
	}

	return 0;
}


