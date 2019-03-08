/*
 * William Wood cssc1167, Nadim Tahmass cssc1158	
 * CS570, Summer 2018
 * Assignment #1, Multithread File Writer
 * main.c
 */

#include <cardThread.h>

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
	printf("Finished up.\n");
	return 0;
}
