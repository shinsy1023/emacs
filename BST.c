//
//  BST.c
//  
//
//  Created by ShinSooyong on 2016. 12. 5..
//
//

#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
    char data;
    struct tnode* parent;
    struct tnode* leftChild;
    struct tnode* rightChild;
} tnode;

typedef struct tree{
    tnode* root;
} tree;

tnode* newtnode(char);
tree* newtree();
void inorder(tnode*);
void preorder(tnode*);
void postorder(tnode*);
void insert(tree*, tnode*);


int main(int argc, char const *argv[]){
    tree* t = newtree();
    char a[10] = {'G', 'D', 'I', 'B', 'F', 'H', 'J', 'A', 'C', 'E'};
    int i;
    for (i = 0; i < 10; i++)
        insert(t, newtnode(a[i]));
    inorder(t -> root);
    preorder(t -> root);
    postorder(t -> root);
    return 0;
}


tnode* newtnode(char newChar){
    tnode* newNode = (tnode*)malloc(sizeof(tnode));
    newNode -> data = newChar;
    newNode -> parent = NULL;
    newNode -> leftChild = NULL;
    newNode -> rightChild = NULL;
    return newNode;
}

tree* newtree(){
    tree* newTree = (tree*)malloc(sizeof(tree));
    newTree -> root = NULL;
    return newTree;
}

void inorder(tree* ){
    
}

void preorder(tree* ){
    
}

void postorder(tree* ){
    
}

void insert(tree* t, tnode* newNode){
    if (t -> root == NULL){
        t -> root = newNode;
        return;
    }
    
    
}
