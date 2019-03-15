#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "words.h"


//is_contain() - return contained word WORD*, or NULL
//word_insert()-add new WORD, void
//word_print()-print list of words, void




//check if list contain word, return pointer to WORD struct if yes, NULL if no
WORD* is_contain(char* name, WORD* head){
	WORD* temp = head;
  	while(temp!=NULL){
		if(strcmp(temp->name,name)==0)
			break;

		temp=temp->next;
	} //end of while

	return temp;
}
//end is_contain


//insert new WORD at the end of the list
void word_insert(char* name, WORD** dprt){
	WORD* temp = (WORD*)malloc(sizeof(WORD));
	temp->name = strdup(name);
	temp->count = 1;
	temp->next = NULL;

	if(*dprt==NULL)
		*dprt = temp;
	else{
		WORD* cur = *dprt;
		while((cur->next)!=NULL){
			cur=cur->next;
		}
		cur->next=temp;
	}
}
//end item_insert


//print word list
void word_print(WORD* head){
	WORD* temp = head;
	char buff[25];
	if(temp==NULL)
		printf("Empty File.\n");
	while(temp!=NULL){
		sprintf(buff, "%-15s: %5i\n", temp->name, temp->count);
		//printf("%-20s: %5i\n", temp->name, temp->count);
		write(1, buff, 25);
		temp=temp->next;
	}
}
//end word_print

