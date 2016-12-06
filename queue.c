#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/* Define  'queue' using typedef and struct.
	queue has front, rear, and size */

typedef struct {
	node* front;
	node* rear;
	int size;
}queue;

/* Prototypes */
queue* init_queue();
void enqueue(queue*, node*);
void dequeue(queue*);
int front(queue*);
void print_queue(queue*);


int main(int argc, char const *argv[]){
	int i;
	queue* q = init_queue();
	enqueue(q, newnode(1));
	printf("front : %d\n", front(q));
	dequeue(q);
	dequeue(q);
	for(i = 2; i<6;i++){
		enqueue(q, newnode(i));
	}
	dequeue(q);
	print_queue(q);
	for(i = 0; i<3;i++) dequeue(q);
	front(q);
	return 0;
}

queue* init_queue(){
	queue* newQueue = (queue*)malloc(sizeof(queue));
	newQueue -> front = NULL;
	newQueue -> rear = NULL;
	newQueue -> size = 0;
	return newQueue;
}

void enqueue(queue* myQueue, node* newNode){
	if (myQueue -> size != 0)
		myQueue -> rear -> next = newNode;
	else 
		myQueue -> front = newNode;
	myQueue -> rear = newNode;
	myQueue -> size++;
}

void dequeue(queue* myQueue){
	if (myQueue -> size == 0){
		printf("NULL\n");
		return;
	}
	node* temp = myQueue -> front;
	myQueue -> front = myQueue -> front -> next;
	temp = NULL;
	myQueue -> size--;
}

int front(queue* myQueue){
	if (myQueue -> size == 0){
		printf("NULL\n");
		return 0;
	}
	return myQueue -> front -> val;
}

void print_queue(queue* myQueue){
	if (myQueue -> size == 0){
		printf("NULL\n");
		return;
	}
	node* temp = myQueue -> front;
	for (int i = 0; i < myQueue -> size - 1; i++){
		printf("%d -> ", temp -> val);
		temp = temp -> next;
	}
	printf("%d\n", temp -> val);
}