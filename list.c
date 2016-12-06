#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/* Define  'list' using typedef and struct.
	queue has head, and size */

typedef struct{
	node* head;
	int size;
}list;

/* Prototypes */
list* init_list();
void appendTo(list* list, node* newnode);
void delAt(list* list, int n);
void print_list(list* list);

int main(int argc, char const *argv[]) {
	list* linked = init_list();
	int i;
	for (i = 1; i < 6; i++) {
		appendTo(linked, newnode(i));
	}
	print_list(linked);
	delAt(linked, -1);
	delAt(linked, 5);
	print_list(linked);
	delAt(linked, 3);
	print_list(linked);
	return 0;
}

list* init_list() {
	list* newList = (list*)malloc(sizeof(list));
	newList -> head = NULL;
	newList -> size = 0;
	return newList;
}

void appendTo(list* list, node* newnode) {
	if (list -> size == 0){
		list -> head = newnode;
		list -> size++;
		return;
	}
	node* temp;
	for (temp = list -> head; temp -> next != NULL; temp = temp -> next);
	temp -> next = newnode;
	list -> size++;
}

void delAt(list* list, int n) {
	if (list -> size < n){
		printf("NULL\n");
		return;
	}
	node* temp = list -> head;
	for (int i = 0; i < n - 1; i++)
		temp = temp -> next;
	node* delNode = temp -> next;
	temp -> next = delNode -> next;
	delNode = NULL;
	list -> size--;
}

void print_list(list* list) {
	node* temp;
	for (temp = list -> head; temp -> next != NULL; temp = temp -> next)
		printf("%d -> ", temp -> val);
	printf("\n");
}