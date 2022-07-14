/*
 *  Peter Adranly
 *  March 1 2022
 */

#include "header9.h"

void savefile(char *filename){					//Save Queue info
	FILE *fp;
	NODE *p;
	fp = fopen(filename, "w");
	if (fp == NULL)	return;
	fprintf(fp, "Name\tSize\n____________\n");
	p = head;
	while (p != NULL){
		fprintf(fp,"%s\t%d\n",p->name,p->gsize);
		p = p->next;
	}
	fclose(fp);
	return;
}

void readfile(char *filename){					//Read Queue info from save file
	FILE *fp;
	char name[MAX_NAME_LENGTH];
	int gsize;
	fp = fopen(filename, "r");
	if (fp == NULL) return;
	fseek(fp,23,SEEK_SET);
	while (fscanf(fp,"%s\t%d",name,&gsize) == 2){
		add(name,gsize);
	}
	fclose(fp);
	return;
}

void *auto_save(void *arg){
	char *filename = (char *)arg;
	while(1){
		pthread_mutex_lock(&mutex);
		savefile(filename);
		pthread_mutex_unlock(&mutex);
		sleep(15);
	}
}

void show_file(char *filename){
	FILE *fp;
	int gsize;
	char name[MAX_NAME_LENGTH];
	fp = fopen(filename, "r");
	if (fp == NULL) return;
	printf("Name\tSize\n____________\n");
	fseek(fp,23,SEEK_SET);
	while (fscanf(fp,"%s\t%d",name,&gsize) == 2){
		printf("%s\t%d\n",name,gsize);
	}
	fclose(fp);
	return;
}		
