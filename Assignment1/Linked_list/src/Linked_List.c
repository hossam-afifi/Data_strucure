/*
 * Linked_List.c
 *
 *  Created on: Oct 8, 2021
 *      Author: amagd
 */


#include "Linked_List.h"



//function add student
void FAdd_Student() {

	char student_data[40];
	struct Sstudent* PNewstudent;
	struct Sstudent* Plaststudent;

	//check list is empty

	if (gPfirststudent == NULL) {
		PNewstudent = (struct Sstudent*) malloc(sizeof(struct Sstudent));
		gPfirststudent = PNewstudent;
	}

	else {
		//navigation until reach to the last record
		Plaststudent = gPfirststudent;
		while (Plaststudent->PNextstudent) {
			Plaststudent = Plaststudent->PNextstudent;
		}  /*end while loop*/
		//create new record
		PNewstudent = (struct Sstudent*) malloc(sizeof(struct Sstudent));
		Plaststudent->PNextstudent = PNewstudent;
	}
	/* fill new record */
	DPRINTF("enter the ID:");
	gets(student_data);
	PNewstudent->Sstudent.ID=atoi(student_data);
	DPRINTF("enter full name:");
	gets(PNewstudent->Sstudent.name);
	DPRINTF("enter the height:");
	gets(student_data);
	PNewstudent->Sstudent.height=atof(student_data);
	DPRINTF("enter the weight:");
	gets(student_data);
	PNewstudent->Sstudent.weight=atof(student_data);
	DPRINTF("enter the subject:");
	gets(PNewstudent->Sstudent.subject);
	//set the next pointer (new_student)null
	PNewstudent->PNextstudent = NULL;
}     /* end function */

//function Delete student
int FDelete_Student(){
	//get the selected
	char temp_text[40];
	unsigned int selected_id;
	struct Sstudent* Pselectstudent = gPfirststudent ;
	struct Sstudent* Pprevstudent = NULL;
	DPRINTF("\nEnter the student id to be delete:");
	gets(temp_text);
	selected_id = atoi(temp_text);
	//list is not empty
	if(gPfirststudent){
		while(Pselectstudent) {
			//compare each node with the selected
			if(Pselectstudent->Sstudent.ID == selected_id) {
				// the first student is not the selected one
				if(Pprevstudent)
					Pprevstudent->PNextstudent = Pselectstudent->PNextstudent;
				// 1st student = ID
				else
					gPfirststudent =Pselectstudent->PNextstudent;

				free(Pselectstudent);
				return 1;
			}
			Pprevstudent = Pselectstudent;
			Pselectstudent = Pselectstudent->PNextstudent ;
		} /*end while loop*/
	}

	DPRINTF("\ncannot find student id");
	return 0;

}     /* end function */

// view list all data student
void FView_student(){
	unsigned int count = 0;
	struct Sstudent* Pcurrentstudent = gPfirststudent;
	if(gPfirststudent == NULL) {
		DPRINTF("\n List is Empty");
		//return 0;
	}
	else {
		while(Pcurrentstudent) {
			DPRINTF("\nrecord number%d",count+1);
			DPRINTF("\n\tID:%d",Pcurrentstudent->Sstudent.ID);
			DPRINTF("\n\tname:%s",Pcurrentstudent->Sstudent.name);
			DPRINTF("\n\theight:%f",Pcurrentstudent->Sstudent.height);
			DPRINTF("\n\tweight:%f",Pcurrentstudent->Sstudent.weight);
			DPRINTF("\n\tsubject:%s",Pcurrentstudent->Sstudent.subject);
			Pcurrentstudent = Pcurrentstudent->PNextstudent;
			count++;

		} /*end while loop*/
	}

}   /* end function */

// delete all list(student)
void FDelete_all(){
	struct Sstudent* Pcurrentstudent = gPfirststudent;
	struct Sstudent* Ptempstudent;
	if(gPfirststudent == NULL) {
		DPRINTF("\n List is Empty");
	}
	else {
		while(Pcurrentstudent) {
			Ptempstudent = Pcurrentstudent;
			Pcurrentstudent = Pcurrentstudent->PNextstudent;
			free(Ptempstudent);
		} /*end while loop*/
		gPfirststudent = NULL;
	} /*end while loop*/

}     /* end function */

//function to get Nth node
struct Sstudent* FGet_Nth_node(unsigned int index){
	unsigned int count = 0;
	struct Sstudent* head = gPfirststudent;
	if(gPfirststudent == NULL) {
		DPRINTF("\n List is Empty");
		return 0;
	}
	else{
		while(head){
			if(count == index){
				DPRINTF("\nStudent ID:%d",head->Sstudent.ID);
				DPRINTF("\nFull name:%s",head->Sstudent.name);
				DPRINTF("\nHeight:%f",head->Sstudent.height);
				DPRINTF("\nWeight:%f",head->Sstudent.weight);
				DPRINTF("\nSubject:%s",head->Sstudent.subject);
				return head;
			}
			else{
				count++;
				head = head->PNextstudent;
			}
			if(head == NULL){
				DPRINTF("\nindex position  is not found");
			}
			else {/*not implementation,misra rule*/}
		}  /*end while loop*/
		return head;
	}
}    /* end function */

#if 0
//FGet_Nth_node method2
struct Sstudent* FGet_Nth_node(unsigned int index){
	unsigned int count = 1;
	struct Sstudent* based = gPfirststudent;
	if(gPfirststudent == NULL) {
		DPRINTF("\n List is Empty"); return 0;
	}
	else {
		/*int lenght = Fcalc_Length();
		 *ch = lenght-index+1;
		 *DPRINTF("\nOutput:%d",ch);
		 */
		while(count != index){
			count++;
			based = based->PNextstudent;
		}
	}
	DPRINTF("\nStudent ID:%d",based->Sstudent.ID);
	DPRINTF("\nFull name:%s",based->Sstudent.name);
	DPRINTF("\nHeight:%f",based->Sstudent.height);
	DPRINTF("\nWeight:%f",based->Sstudent.weight);
	DPRINTF("\nSubject:%s",based->Sstudent.subject);

	return based;
}   /* end function */
#endif

//n’th node from the first of a Linked List method
struct Sstudent* get_first_list(unsigned int index) {
	unsigned int count = 1;
	struct Sstudent* based = gPfirststudent;
	if(gPfirststudent == NULL) {
		DPRINTF("\n List is Empty"); return 0;
	}
	else {
		while(count != index){
			count++;
			based = based->PNextstudent;
		}
	}
	DPRINTF("\nStudent ID:%d",based->Sstudent.ID);
	DPRINTF("\nFull name:%s",based->Sstudent.name);
	DPRINTF("\nHeight:%f",based->Sstudent.height);
	DPRINTF("\nWeight:%f",based->Sstudent.weight);
	DPRINTF("\nSubject:%s",based->Sstudent.subject);

	return based;
}   /* end function */

int Fcalc_Length(){
	unsigned int count = 0;
	struct Sstudent* Pcurrentstudent = gPfirststudent;
	if(Pcurrentstudent == NULL) { return 0; }
	else { 	/*not implementation, misra rule */}
	while(Pcurrentstudent) {
		Pcurrentstudent = Pcurrentstudent->PNextstudent;
		count++;
		if(Pcurrentstudent == NULL){  return count; }
		else {/*not implementation,misra rule*/}
	} /*end while loop*/
	return 1;
}    /* end function */

//calculate length of list
int FLength_iterative( ){
	unsigned int count = 0;
	struct Sstudent* Pcurrentstudent = gPfirststudent;
	if(Pcurrentstudent == NULL) {
		DPRINTF("\n List is Empty");
		return 0;
	}
	else {
		while(Pcurrentstudent) {
			Pcurrentstudent = Pcurrentstudent->PNextstudent;
			count++;
		}/*end while loop*/
		DPRINTF("\nLength of list:%d",count);
	}
	return count;
}    /* end function */

//Length_recursive of list
int FLength_recursive(struct Sstudent*head){
	 static unsigned int count = 0;
	if(head == NULL){
		DPRINTF("\nLength of list:%d",count);

	}
	else{
		count++;
		return  1+FLength_recursive(head->PNextstudent);
	}
	count = 0;
	return count;
}    /* end function */

//n’thnode from the end of a Linked List method(1)
struct Sstudent* Fnt_node(unsigned int index){

	unsigned int length ,numb =0;
	struct Sstudent* based = gPfirststudent;

	length = FLength_iterative();

	if(gPfirststudent == NULL) {
		DPRINTF("\n List is Empty");
		return 0;
	}
	else {
		numb = length - index+1;
		based= get_first_list(numb);
	}
	return based;
}

//n’thnode from the end of a Linked List method(2)
struct Sstudent* Fnt_nodes(unsigned int index){
	unsigned char count = 0;
	struct Sstudent* first =gPfirststudent,*ref = gPfirststudent;
	if(ref == NULL || count ==index) {
		DPRINTF("\n List is Empty");
		return NULL;
	}
	if(index > Fcalc_Length()) {
		DPRINTF("\nindex input is error");
		return NULL;
	}

	while(count != index) {
		ref = ref->PNextstudent;
		count++;
	}  /*end while loop*/
	while(ref){
		ref = ref->PNextstudent;
		first = first->PNextstudent;
	}
	DPRINTF("\nStudent ID:%d",first->Sstudent.ID);
	DPRINTF("\nFull name:%s",first->Sstudent.name);
	DPRINTF("\nHeight:%f",first->Sstudent.height);
	DPRINTF("\nWeight:%f",first->Sstudent.weight);
	DPRINTF("\nSubject:%s",first->Sstudent.subject);
	return first;
}   /* end function */

//find the middle of a linked list
struct Sstudent* FGet_middle_student() {
	struct Sstudent* Pslow = gPfirststudent;
	unsigned int length =  Fcalc_Length();
	unsigned int index;

	if(Pslow == NULL) {
		DPRINTF("\n List is Empty"); return 0;
	}
	else {
		if(length%2 == 0)
			/*length is even*/
			index =length/2;
		else
			/*length is odd */
			index = (length-1)/2;
		Pslow =FGet_Nth_node(index);

	}
	return Pslow;
}   /* end function */

//Detect loop in a linked list
void FDetect_loop(){
	//one step initial pointers (Pslow,Pfast)
	struct Sstudent *Pslow = gPfirststudent;
	struct Sstudent *Pfast = gPfirststudent;

	while(Pslow && Pfast && Pfast->PNextstudent) {
		Pslow = Pslow->PNextstudent;
		Pfast = Pfast->PNextstudent->PNextstudent;
		if(Pslow == Pfast){
			DPRINTF("\nList Found Loop");
			break;	}
		else{
			DPRINTF("\nDose not Found Loop");
			break;
		}
	}  /*end while loop*/

}   /* end function */

//reverse List

void FReverse(){
	struct Sstudent* currentstudent = gPfirststudent;
	struct Sstudent* next;
	struct Sstudent* prev = NULL;

	if(gPfirststudent == NULL) {
		DPRINTF("\nNULL");
	}

		while (currentstudent != NULL){
			next = currentstudent->PNextstudent;
			 currentstudent->PNextstudent = prev;
			 prev = currentstudent ;
			 currentstudent = next;

		}  /*end while loop*/
		gPfirststudent = prev;
		DPRINTF("\nReverse List");


}  /* end function */


