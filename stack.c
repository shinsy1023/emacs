#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/* Define 'stack' using typedef and struct.
	stack has top, size */

typedef struct _Stack{
	node* top;
	int size;
}stack;

/* Prototypes */
stack* init_stack();
void push(stack*, node*);
void pop(stack*);
int top(stack*);
void print_stack(stack*);

int main(int argc, char const *argv[]) {
	int i;
	stack* s = init_stack();
	push(s, newnode(1));
	printf("top : %d\n", top(s));
	pop(s);
	pop(s);
	for (i = 2; i < 6; i++) {
		push(s, newnode(i));
	}

	pop(s);
	print_stack(s);
	for (i = 0; i < 3; i++) pop(s);
	top(s);
	return 0;
}

stack* init_stack(){
	stack* newStack = (stack*)malloc(sizeof(stack));
	newStack -> top = NULL;
	newStack -> size = 0;
	return newStack;
}

void push(stack* myStack, node* newNode){
	newNode -> next = myStack -> top;
	myStack -> top = newNode;
	(myStack -> size)++;
}

void pop(stack* myStack){
	if (myStack -> size == 0){
		printf("NULL\n");
		return;
	}
	node* temp = myStack -> top;
	myStack -> top = temp -> next;
	temp = NULL;
	(myStack -> size)--;
}

int top(stack* myStack){
	if (myStack -> size == 0){
		printf("NULL\n");
		return 0;
	}
	return myStack -> top -> val;
}

void print_stack(stack* myStack){
	if (myStack -> size == 0){
		printf("NULL\n");
		return;
	}
	node* temp = myStack -> top;
	for (int i = 0; i < myStack -> size - 1; i++){
		printf("%d ->", temp -> val);
		temp = temp -> next;
	}
	printf("%d\n", temp -> val);
}