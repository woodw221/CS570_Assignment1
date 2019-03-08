/*
 * William Wood cssc1167, Nadim Tahmass	cssc1158
 * CS570, Summer 2018
 * Assignment #1, Multithread File Writer
 * threadPlayer.c
 */


#include <cardThread.h>

void *diamondPrint(void *vargp){
	int i = 1;
	do	{
		usleep(125000);
		sem_wait(&FLAG);
		fptr = fopen("STACK.txt","a");

		printf("Thread ");
		printf("%lu", pthread_self());
		printf(" is running\n");
		fprintf(fptr, "Diamond ");

		if(i == 1){
			fprintf(fptr, "A\n");
		}
		else if(i == 11){
			fprintf(fptr, "J\n");
		}
		else if(i == 12){
			fprintf(fptr, "Q\n");
		}
		else if(i == 13){
			fprintf(fptr, "K\n");
		}
		else{
			fprintf(fptr, "%d\n", i);
		}

		fclose(fptr);
		sem_post(&FLAG);
		i = i+1;
	}
	while (i < 14);
	return NULL;
}

void *clubPrint(void *vargp){
	int i = 1;
	do	{
		usleep(250000);
		sem_wait(&FLAG);
		fptr = fopen("STACK.txt","a");		

		printf("Thread ");
		printf("%lu", pthread_self());
		printf(" is running\n");

		fprintf(fptr, "Club ");

		if(i == 1){
			fprintf(fptr, "A\n");
		}
		else if(i == 11){
			fprintf(fptr, "J\n");
		}
		else if(i == 12){
			fprintf(fptr, "Q\n");
		}
		else if(i == 13){
			fprintf(fptr, "K\n");
		}
		else{
			fprintf(fptr, "%d\n", i);
		}
		
		fclose(fptr);
		sem_post(&FLAG);
		i = i+1;
	}
	while (i < 14);
	return NULL;
}

void *heartPrint(void *vargp){
	int i = 1;
	do	{
		usleep(500000);
		sem_wait(&FLAG);
		fptr = fopen("STACK.txt","a");

		printf("Thread ");
		printf("%lu", pthread_self());
		printf(" is running\n");

		fprintf(fptr, "Heart ");

		if(i == 1){
			fprintf(fptr, "A\n");
		}
		else if(i == 11){
			fprintf(fptr, "J\n");
		}
		else if(i == 12){
			fprintf(fptr, "Q\n");
		}
		else if(i == 13){
			fprintf(fptr, "K\n");
		}
		else{
			fprintf(fptr, "%d\n", i);
		}

		fclose(fptr);
		sem_post(&FLAG);
		i = i+1;
	}
	while (i < 14);
	return NULL;
}

void *spadePrint(void *vargp){
	int i = 1;
	do	{
		usleep(750000);
		sem_wait(&FLAG);
		fptr = fopen("STACK.txt","a");

		printf("Thread ");
		printf("%lu", pthread_self());
		printf(" is running\n");

		fprintf(fptr, "Spade ");

		if(i == 1){
			fprintf(fptr, "A\n");
		}
		else if(i == 11){
			fprintf(fptr, "J\n");
		}
		else if(i == 12){
			fprintf(fptr, "Q\n");
		}
		else if(i == 13){
			fprintf(fptr, "K\n");
		}
		else{
			fprintf(fptr, "%d\n", i);
		}

		fclose(fptr);
		sem_post(&FLAG);
		i = i+1;
	}
	while (i < 14);
	return NULL;
}
