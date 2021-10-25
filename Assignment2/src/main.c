/*
 * main.c
 *
 *  Created on: Oct 22, 2021
 *      Author: amagd
 */


#include "CA.h"

int main (){
	volatile int i=0;

	setup();

	while(1){

		CA_state();
		//TIME DELAY
		for(i;i<1000;i++);

	}

	return 0;
}

void setup() {

	CA_state = STATE(CA_Waiting);
}
