#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int num;
	struct _node* next;
}node;

node* push(node* top, int what){
	node* up=(node*)malloc(sizeof(node*));
	up->num=what;
	up->next=top;
	return up;
}

node* pop(node* top){
	printf("%d\n",top->num);
	return top->next;
}

int main(int argc, char const *argv[]){
	node* top=(node*)malloc(sizeof(node*));
	int what;
	while (1){
		scanf("%d", &what);
		if (what==1){
			scanf("%d",&what);
			top=push(top, what);
		}else if(what==2){
			top=pop(top);
		}
	}
	return 0;
}