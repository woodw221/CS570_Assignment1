# William Wood cssc1167, Nadim Tahmass cssc1158
# CS570, Summer 2018
# Assignment #1, Multithread File Writer
# makefile
 

player: main.c threadPlayer.c
	gcc -pthread -o player threadPlayer.c main.c -I.
