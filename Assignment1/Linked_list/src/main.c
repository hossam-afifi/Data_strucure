/*
 ============================================================================
 Name        : main.c
 Author      : Linked List
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Linked_List.h"

int main(void) {
	char user[30];
	unsigned int input=0,index=0,count=1,password;

	DPRINTF(".....MASTRING EMBEDDED SYSTEM.....\n");

	DPRINTF("Enter Username: ");
	gets(user);
	DPRINTF("\nEnter Password:");
	scanf("%d",&password);
	fflush(stdout); fflush(stdin);
	if(password == 251993) {
		DPRINTF("\n##### Welcome to: %s #####",user);
	}
	else {
		while(password !=251993){
			DPRINTF("\nEnter Password:");
			fflush(stdout); fflush(stdin);
			scanf("%d",&password);
			fflush(stdout); fflush(stdin);
			count++;
			if(password ==251993){
				DPRINTF("\nPassword is correct");
				DPRINTF("\n##### Welcome to: %s #####",user);
				break;
			}
			if(count ==3){
				exit(0);
			}
			if(password !=251993)
				DPRINTF("\n####Password is Wrong####");
		}
	}

	while(1) {

		DPRINTF("\n=======================================\n");
		DPRINTF("Enter your choice: \n");
		DPRINTF("1 - Add Student to the list\n");
		DPRINTF("2 - Delete student from the list\n");
		DPRINTF("3 - View the students list\n");
		DPRINTF("4 - Delete All the list\n");
		DPRINTF("5 - get Nth node in a Linked List\n");
		DPRINTF("6 - Length of a Linked List Iterative\n");
		DPRINTF("7 - Length of a Linked List Recursive\n");
		DPRINTF("8 - n’thnode from the end of a Linked List method(1)\n");
		DPRINTF("9 - n’thnode from the end of a Linked List \n");
		DPRINTF("10 - middle of a given linked list\n");
		DPRINTF("11 - Detect Loop in List\n");
		DPRINTF("12 - Reverse the List\n");
		DPRINTF("13 - quit\n");
		DPRINTF("=======================================\n");
		DPRINTF("enter input:");
		scanf("%d",&input);
		fflush(stdout); fflush(stdin);

		switch(input) {
		case 1: {
			FAdd_Student();
			break;
		}
		case 2: {
			FDelete_Student();
			break;
		}
		case 3: {
			FView_student();
			break;
		}
		case 4: {
			FDelete_all();
			break;
		}
		case 5: {
			DPRINTF("\nenter index number:");
			scanf("%d",&index);
			FGet_Nth_node(index);
			break;
		}
		case 6: {
			FLength_iterative();
			break;
		}
		case 7: {
			FLength_recursive(gPfirststudent);
			break;
		}
		case 8: {
			DPRINTF("\nenter index number:");
			scanf("%d",&index);
			Fnt_node(index);
			break;
		}
		case 9: {
			DPRINTF("\nenter index numbe:");
			scanf("%d",&index);
			Fnt_nodes((unsigned int) index);
			break;
		}
		case 10: {
			FGet_middle_student();
			break;
		}
		case 11: {
			FDetect_loop();
			break;
		}
		case 12: {
			FReverse();
			break;
		}
		case 13 :
			exit(0);
			break;
		default :
			DPRINTF("input is not correct try to input again\n");
			break;
		}

	}


	return EXIT_SUCCESS;
}
