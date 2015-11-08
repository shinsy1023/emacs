#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int num;
	struct _node* next;
}node;

void push(node* top){

}

void pop(node* top){

}

int main(int argc, char const *argv[]){
	node* top=(node*)malloc(sizeof(node*));
	int what;
	while (1){
		scanf("%d", &what);
		if (what==1){
			push(top);
			printf("%d",top->num);
		}else if(what==2){
			pop(top);
		}
	}
	return 0;
}