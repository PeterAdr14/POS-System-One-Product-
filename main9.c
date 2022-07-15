/*
 *  Peter Adranly
 *  Mar 1 2022
 */

#include "header9.h"

NODE *head = NULL;
NODE *tail = NULL;

pthread_mutex_t mutex;

int main(int argc, char *argv[]){			//Menu or Option select
	int opt;
	int out = 1;
	int size;
	int count;

	char name[MAX_NAME_LENGTH];
	if (argc != 2){
		printf("No file name given\n");
		return;
	}
	pthread_t th;
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&th,NULL,auto_save,(void*)argv[1]);

	readfile(argv[1]);
	while(out){
		printf("Menu\n 1--Add an Order\n 2--Fulfill an Order\n 3--List the Orders\n 4--Search by Size\n 5--Backwards List\n 6--List Length\n 7--Show Save File\n 0--Quit\n");
		scanf("%d",&opt);
		switch(opt){
			case(1):
				pthread_mutex_lock(&mutex);
				printf("What is the name for the order?\n");
				scanf("%s",name);
				if (check_duplicate(name) == 1) break;
				printf("How many are in this order?\n");
				scanf("%d",&size);
				add(name,size);
				pthread_mutex_unlock(&mutex);
				break;
			case(2):
				pthread_mutex_lock(&mutex);
				fulfill();
				pthread_mutex_unlock(&mutex);
				break;
			case(3):
				list();
				break;
			case(4):
				search_size();
				break;
			case(5):
				backwards(head);
				break;
			case(6):
				count = list_length(head);
				printf("List Length: %d\n",count);
				break;
			case(7):
				show_file(argv[1]);
				break;
			case(0):
				pthread_cancel(th);
				savefile(argv[1]);
				quit(head,head->next);
				out = 0;
				break;
			default:
				printf("Please try again\n");
				break;
		}
	}
}
