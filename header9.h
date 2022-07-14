/*
 *  Peter Adranly
 *  March 1 2022
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_NAME_LENGTH 10
#define NODE struct node 

struct node{
	char name[MAX_NAME_LENGTH];
	int gsize;
	NODE *next;
};

void add(char *name, int gsize);
void fulfill();
void list();
void search_size();
int check_duplicate(char name[]);
void savefile(char *x);
void readfile(char *x);
void backwards(NODE *x);
int list_length(NODE *x);
void quit(NODE *x,NODE *y);
void *auto_save(void *x);

extern pthread_mutex_t mutex;

extern NODE *head;
extern NODE *tail;
