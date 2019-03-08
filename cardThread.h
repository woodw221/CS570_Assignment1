/*
 * William Wood cssc1167, Nadim Tahmass	cssc1158
 * CS570, Summer 2018
 * Assignment #1, Multithread File Writer
 * cardThread.h
 */



/*
 *	semaphore and file required
 *	All of the different thread instructions
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t FLAG;
FILE *fptr;

/*
 *  All of the functions below are the suit write actions
 *  All of them will be hard coded to do what each thread
 *  has been specified to do in the assignment. To print
 *  A, J, Q, K, a variable I will be checked to see if the
 *  function has ran 1, 11, 12, or 13, times respectively.
 */

void *diamondPrint(void *vargp);
void *clubPrint(void *vargp);
void *heartPrint(void *vargp);
void *spadePrint(void *vargp);
