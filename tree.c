#include "tree.h"

#define RIGHT (search -> rChild)
#define LEFT (search -> lChild)
#define PARENT (search -> parent)
#define HEIGHT (search -> height)
#define DATA (search -> data)
#define TRUE 1
#define FALSE 0

int insert(node **root, int insertData){
	if ((*root) -> height == 0){
		(*root) = createNode(insertData);
		return TRUE;
	} else {
		node* search = searchNode(root, insertData);
		if (isLeaf(search))
			setHeight(&search, 1);
		if (DATA > insertData){
			LEFT = createNode(insertData);
			LEFT -> parent = search;
		}
		else {
			RIGHT = createNode(insertData);
			RIGHT -> parent = search;
		}
		return insertData;
	}
}

node *createNode(int data){
	node* newNode = (node*)malloc(sizeof(node));
	newNode -> height = 1;
	newNode -> data = data;
	newNode -> lChild = NULL;
	newNode -> rChild = NULL;
	newNode -> parent = NULL;
	return newNode;
}

node* searchNode(node** root, int data){
	node *search = (*root);
	while (TRUE){
		if (DATA > data){
			if (LEFT != NULL){
				search = LEFT;
			}
			else
				return search;
		} else if (DATA < data){
			if (RIGHT != NULL)
				search = RIGHT;
			else
				return search;
		} else {
			return search;
		}
	}
}

int search(node *search, int data){
	if (search == NULL){
		return 0;
	} else {
		while (TRUE){
			if (DATA > data){
				if (LEFT == 0){
					return 0;
				} else {
					search = LEFT;
				}
			} else if (DATA < data){
				if (RIGHT == 0){
					return 0;
				} else {
					search = RIGHT;
				}
			} else {
				return DATA;
			}
		}
	}
}

void setHeight(node **salmon, int increment){
	node *search = *salmon;
	if(isRoot(search)){
		HEIGHT += increment;
	} else {
		if ((PARENT -> height - 1) == HEIGHT)
			setHeight(&PARENT, increment);
		HEIGHT += increment;
	}
}

int removeNode(node **root, int data){
	node* search = searchNode(root, data);
	node* findLeaf = RIGHT;
	while(findLeaf -> lChild != NULL)
		findLeaf = findLeaf -> lChild;
	if (PARENT -> lChild == search)
		PARENT -> lChild = findLeaf;
	else
		PARENT -> rChild = findLeaf;
	if (isLeaf(findLeaf -> parent))
		setHeight(&(findLeaf -> parent), (-1));
	findLeaf -> parent -> lChild = NULL;
	findLeaf -> height = HEIGHT;
	findLeaf -> parent = PARENT;
	findLeaf -> lChild = LEFT;
	findLeaf -> rChild = RIGHT;
	return data;
}

void postOrder(node *search){
	if (search != NULL){
		if (HEIGHT != 1){
			postOrder(LEFT);
			postOrder(RIGHT);
		}
		printf("%d -> ", DATA);
	}
}

void preOrder(node *search){
	if (search != NULL){
		printf("%d -> ", DATA);
		if (HEIGHT != 1){
			preOrder(LEFT);
			preOrder(RIGHT);
		}
	}
}

void inOrder(node *search){
	if (search != NULL){
		if (HEIGHT != 1)
			inOrder(LEFT);
		printf("%d -> ", DATA);
		if (HEIGHT != 1)
			inOrder(RIGHT);
	}
}

int isRoot(node* checkNode){
	if (checkNode -> parent == NULL)
		return TRUE; 
	else 
		return FALSE;
}

int isLeaf(node* checkNode){
	if (checkNode -> lChild == NULL && checkNode -> rChild == NULL)
		return TRUE;
	else
		return FALSE;
}

int main(void){
	node* root = (node*)malloc(sizeof(node*));
	root -> height = 0;
	insert(&root, 50);
	insert(&root, 30);
	insert(&root, 20);
	insert(&root, 11);
	insert(&root, 24);
	insert(&root, 40);
	insert(&root, 32);
	insert(&root, 47);
	insert(&root, 70);
	insert(&root, 60);
	insert(&root, 59);
	insert(&root, 62);
	insert(&root, 80);
	insert(&root, 74);
	insert(&root, 84);
	removeNode(&root, 70);
	inOrder(root);
	printf("\n");
	postOrder(root);
	printf("\n");
	preOrder(root);
	printf("\n");
}