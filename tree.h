#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
	int data;
	int height;
	struct _Node *parent;
	struct _Node *lChild;
	struct _Node *rChild;
}node;

int insert(node **root, int data);
int search(node *search, int data);
void postOrder(node *root);
void preOrder(node *root);
void inOrder(node *root);
void setHeight(node **salmon, int increment);
int recursionRemove(node **target);
int isRoot(node* checkNode);
int isLeaf(node* checkNode);
int removeNode(node **root, int data);
node* createNode(int data);
node* searchNode(node** root, int data);