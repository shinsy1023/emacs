#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int num;
	struct _node* next;
}node;

node* add(node* tail, int what){
	tail->num=what;
	tail->next=(node*)malloc(sizeof(node*));
	tail=tail->next;
	return tail;
}

node* queue(node* head){
	printf("%d\n", head->num);
	head=head->next;
}

int main(){
	int choice;
	node* head=(node*)malloc(sizeof(node*));
	node* tail=(node*)malloc(sizeof(node*));
	tail=head;
	while(1){
		scanf("%d", &choice);
		if (choice==1){
			scanf("%d", &choice);
			tail=add(tail, choice);
		}else if(choice==2){
			head=queue(head);
		}
	}
	return 0;
}