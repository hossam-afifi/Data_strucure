/*
 * state.h
 *
 *  Created on: Oct 24, 2021
 *      Author: amagd
 */

#ifndef STATE_H_
#define STATE_H_


#define state_define(_statefunc_)  void ST_##_statefunc_()

#define STATE(_statefunc_)  ST_##_statefunc_


#define DPRINTF(...)  {   fflush(stdout); fflush(stdin); \
	                       printf(__VA_ARGS__);\
	                       fflush(stdout); fflush(stdin); }


#endif /* STATE_H_ */
