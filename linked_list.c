#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int num;
	struct _node* next;
}node;

void add(node *a, int num, int count){
	int i;
	for (i=0;i<count;i++){
		a=a->next;
	}
	a->num=num;
	a->next=(node*)malloc(sizeof(node*));
	a=a->next;
}

void print(node *head, int count){
	int i;
	for (i=0; i<count; i++){
		printf("%d -> ",head->num);
		head=head->next;
	}
	printf("\n");
}

int main(){
	node* head=(node*)malloc(sizeof(node*));
	int tmp;
	int scan;
	int count=0;
	while (1){
		printf("0=quit\n");
		scanf("%d",&scan);
		if (scan==0){
			break;
		}
		add(head, scan, count);
		count++;
		print(head, count);
	}
	return 0;
}