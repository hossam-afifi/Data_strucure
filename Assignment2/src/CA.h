/*
 * CA.h
 *
 *  Created on: Oct 22, 2021
 *      Author: amagd
 */

#ifndef CA_H_
#define CA_H_


#include "stdio.h"
#include "stdlib.h"
#include "state.h"

enum {
	CA_Waiting,
	CA_Driving
}CA_state_id;

//declare sates functions Collision Avoidance
state_define(CA_Waiting);
state_define(CA_Driving);

// state pointer to function
extern void (*CA_state)();

// APIS
void setup();
int US_Get_distance_random (int low, int range, int count);


#endif /* CA_H_ */
