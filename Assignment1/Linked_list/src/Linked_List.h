/*
 * Linked_List.h
 *
 *  Created on: Oct 8, 2021
 *      Author: amagd
 */



#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "string.h"


#define DPRINTF(...)  { fflush(stdin); fflush(stdout); \
						printf(__VA_ARGS__); \
						fflush(stdin); fflush(stdout);}


typedef unsigned int uini8t;


struct SDATA{
	uini8t ID;
	char name[40],subject[10];
	float height,weight;

};

//linked list node
struct Sstudent{
	struct SDATA Sstudent;
	struct Sstudent *PNextstudent;
};

struct Sstudent *gPfirststudent;

/* APIS
 * Prototypes Functions
 */

void FAdd_Student();
int FDelete_Student();
void FView_student();
void FView(struct Sstudent* head);
void FDelete_all();
struct Sstudent* FGet_Nth_node(unsigned int index);
int Fcalc_Length();
int FLength_iterative();
int FLength_recursive(struct Sstudent*head);
struct Sstudent* get_first_list(unsigned int index);
struct Sstudent* Fnt_node(unsigned int index);
struct Sstudent* Fnt_nodes(unsigned int index);
struct Sstudent* FGet_middle_student();
void FDetect_loop();
void FReverse();

#endif /* LINKED_LIST_H_ */
