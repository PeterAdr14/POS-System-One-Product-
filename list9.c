/*
 *  Peter Adranly
 *  March 1 2022
 */

#include "header9.h"

void add(char *name, int gsize){					//Adds order
	NODE *temp;
	temp = (NODE *) malloc (sizeof(NODE));
	strcpy(temp->name,name);
	temp->gsize = gsize;
	if (head == NULL){
		temp->next = NULL;
		head = temp;
		tail = temp;
	}else{
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
	printf("Order Placed!\n");
	return;
}

void fulfill(){					//Fulfills an Order
	int made;
	NODE *p = head;
	NODE *g;
	if (head == NULL){
		printf("No Orders to Fill\n");
		return;
	}
	printf("How many drinks were made?\n");
	scanf("%d",&made);
	while (p !=NULL){
		if(p->gsize <= made) {
			made -= p->gsize;
			printf("%s's order was fulfilled\n",p->name);
			if(p == head){
				head = p->next;
				free(p);
			}else if(p == tail){
				tail = g;
				g->next = NULL;
				free(p);
			}else if(head == tail){
				free(p);
			}else{
				g->next = p->next;
				free(p);
			}
		}
		g = p;
		p = p->next;
	}
	return;	
}


void list(){				//Show Current List
	NODE *p = head;
	if (head == NULL){
		printf("No Orders in Queue\n");
		return;
	}
	while (p != NULL){
		printf("Name:%s\tOrdered: %d\n",p->name,p->gsize);
		p = p->next;
	}
	return;
}

void search_size(){		//Search for order size same or smaller
	int size;
	int check = 0;
	NODE *p = head;
	printf("What size order are you searching for?\n");
	scanf("%d",&size);
	while (p != NULL){
		if (p->gsize <= size){
			printf ("%s %d\n",p->name,p->gsize);
			check = 1;
		}
		p = p->next;
	}
	if (check == 0) printf("None of that size or smaller\n");
	return;
}

int check_duplicate(char new_name[MAX_NAME_LENGTH]){		//Checks if new name input is duplicate
	NODE *p = head;
	while (p != NULL){
		if (strcmp(p->name,new_name) == 0){
			printf("Please use a different name\n");
			return 1;			
		}
		p = p->next;
	}
	return 0;
}

void backwards(NODE *p){					//Will Print List Backwards
	if (p->next == NULL){
		printf("Name:%s\tSize:%d\n",p->name,p->gsize);
		return;
	}else{
		backwards(p->next);
		printf("Name:%s\tSize:%d\n",p->name,p->gsize);
	}	
}

int list_length(NODE *p){			//Will print the length of the list
	int count = 0;
	if (p->next == NULL){
		count ++;
		return count;
	}else{
		count = 1 + list_length(p->next);
		return count;
	}
}

void quit(NODE *p,NODE *q){
	if (q == tail){
		free(p);
		free(q);
		return;
	}else {
		head = q;
		free(p);
		quit(q, q->next);
		return;
	}
} 
