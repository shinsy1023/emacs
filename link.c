
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
int num;
struct _Node* next;
} node;

void node_append(node* n, int i) {
	if(n == 0x0) {
		n = (node*) malloc(sizeof(node));
		n->num = i;
	} else {
		while(n->next != 0x0) {
			n=n->next;
		}
		n->next = (node*) malloc(sizeof(node));
		n->num = i;
	}
}

void node_insert(node* n, int i, int p) {
	int j;
	node *target = (node*) malloc(sizeof(node));

	for(j=1;j<p;j++)
		n=n->next;

	target->num = i;

	target->next = n->next->next;
	n->next = target;
}

void node_remove(node* n, int p) {
	int j;
	node* target = NULL;

	for(j=1; j<p;j++)
		n=n->next;

	target = n->next;
	n->next = n->next->next;

	free(target);
}

void node_print(node* n, int p) {
	int i=0;

	while(i != p) {
		i++;
		n=n->next;
	}
	printf("Linked List Number: %d, %p\n", n->num, n);
}

void node_print_all(node* n) {
	printf("Printing Linked List Number: \n");
	while(n->next != 0x0) {
		printf("%d %p\n", n->num, n);
		n=n->next;
	}
}

int main(int argc, char* argv[]) {
	int i, j, k;
	char c;

	node *head = (node*) malloc(sizeof(node));
	head->next = NULL;
	printf("Main: %p, %p\n", head, head->next);


	while(1) {
		printf("Input command(I: insert, A: append, C: Append sequentially, D: delete, P: print, R: print all. E: exit.\n");
		scanf(" %c", &c);
		if(c =='E' || c == 'e') break;
		switch(c) {
			case 'I':
			case 'i':
				printf("Input number and position (For example, 4 5 measn put number 4 in fifth node)\n");
				scanf("%d %d", &i, &j);
				node_insert(head, i, j);
				break;
			case 'A' :
			case 'a' :
				printf("Input number (for example, 4 means append number 4)\n");
				scanf("%d", &i);
				node_append(head, i);
				break;
			case 'C' :
			case 'c' :
				printf("Input number (for example, 4 8 means append number 4 5 6 7 8 in a row)\n");
				scanf("%d %d", &i, &j);
				for(k=i; k<=j; k++)
					node_append(head, k);
				break;
			case 'D' :
			case 'd' :
				printf("Input node position to delete (For example, 5 means delete node in postition 5)\n");
				scanf("%d", &i);
				node_remove(head, i);
				break;
			case 'P' :
			case 'p' :
				printf("Input node position to print(For example, 5 means print number in fifth node)\n");
				scanf("%d", &i);
				node_print(head, i);
				break;
			case 'R' :
			case 'r' :
				node_print_all(head);
				break;
		}
	}


	free(head);
	return 0;
}