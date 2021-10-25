/*
 * CA.c
 *
 *  Created on: Oct 22, 2021
 *      Author: amagd
 */

#include "CA.h"

//variables
int CA_speed = 0;
int CA_distance = 0;
int CA_threoshold = 50;

void (*CA_state)();

state_define(CA_Waiting){

	/* state name */
	CA_state_id = CA_Waiting;

	/*State action*/
	CA_speed = 0;
	/*DC_motor speed*/
	CA_distance = US_Get_distance_random (45,55,1);
	/*Event_Check*/
	(CA_distance <= CA_threoshold) ? (CA_state = STATE(CA_Waiting)):(CA_state = STATE(CA_Driving));
	DPRINTF("CA_Waiting=%d , CA_speed=%d\n",CA_distance,CA_speed);

}



state_define(CA_Driving){

	/* state name */
	CA_state_id = CA_Driving;

	/*State action*/
	CA_speed = 30;
	/*DC_motor speed*/
	CA_distance = US_Get_distance_random (45,55,1);
	/*Event_Check*/
	(CA_distance <= CA_threoshold) ? (CA_state = STATE(CA_Waiting)):(CA_state = STATE(CA_Driving));
	DPRINTF("CA_Driving=%d , CA_speed=%d\n",CA_distance,CA_speed);

}


int US_Get_distance_random (int low, int range, int count) {

	int num_random =0 ;

	for(int i=0; i< count; i++)
		num_random = (rand() %(range - low +1 ))+ low ;

	return num_random;

}






