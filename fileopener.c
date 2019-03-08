#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t FLAG;
FILE *fptr;

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

int main(){

	fptr = fopen("STACK.txt","w");
	

	if(fptr == NULL){
		printf("File did not create!");
		exit(0);
	}
	
	fprintf(fptr, "Process ID: ");
	fprintf(fptr, "%d\n", getpid());
	fclose(fptr);
	sem_init(&FLAG, 0, 1);
	pthread_t diamond, club, heart, spade;

	pthread_create(&diamond, NULL, diamondPrint, NULL);
	pthread_create(&club, NULL, clubPrint, NULL);
	pthread_create(&heart, NULL, heartPrint, NULL);
	pthread_create(&spade, NULL, spadePrint, NULL);

	pthread_join(diamond, NULL);
	pthread_join(club, NULL);
	pthread_join(heart, NULL);
	pthread_join(spade, NULL);

	sem_destroy(&FLAG);
	return 0;
}
