#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
int num;
struct _Node* next;
} node;

int main(int argc, char const *argv[])
{
	node *head = (node*) malloc(sizeof(node));
	printf("Main: %p, %p\n", head, head->next);
	return 0;
}