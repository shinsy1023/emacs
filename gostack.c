#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct node{
	int num;
	struct node* stack;
}node;

typedef struct numx{
	int num;
	struct numx* next;
}numx;

node* num(node* head, int num);
node* pop(node* head);
void inv(node* head);
void swp(node* head);
node* add(node* head);
node* sub(node* head);
node* mul(node* head);
node* _div(node* head);
node* mod(node* head);
numx* insert(numx* fir, int num);
numx* del(numx* fir);


node* num(node* head, int number){
	node* top=(node*)malloc(sizeof(node));
	top->num=number;
	top->stack=head;
	return top;
}

node* pop(node* head){
	if (head!=NULL){
		printf("%d\n", head->num);
		if (head->stack==NULL){
			return NULL;
		}else{
			return head->stack;
		}
	}else{
		return NULL;
	}
}

void inv(node* head){
	head->num=head->num*(-1);
}

void swp(node* head){
	int tmp=head->stack->num;
	head->stack->num=head->num;
	head->num=tmp;
}

node* add(node* head){
	node* tmp=head->stack;
	tmp->num=head->num+tmp->num;
	return tmp;
}

node* sub(node* head){
	node* tmp=head->stack;
	tmp->num=tmp->num-head->num;
	head=NULL;
	return tmp;
}

node* mul(node* head){
	node* tmp=head->stack;
	tmp->num=head->num*tmp->num;
	head=NULL;
	return tmp;
}

node* _div(node* head){
	node* tmp=head->stack;
	tmp->num=(int)(tmp->num/head->num);
	head=NULL;
	return tmp;
}

node* mod(node* head){
	node* tmp=head->stack;
	tmp->num=tmp->num%head->num;
	head=NULL;
	return tmp;
}

numx* insert(numx* fir, int num){
	numx* tmp=fir;
	while(tmp!=NULL){
		tmp=tmp->next;
	}
	tmp->num=num;
}

numx* del(numx* fir){
	int a=fir->num;
	fir=fir->next;
	return a;
}

int main(int argc, char const *argv[]){
	int i=0, j=0, count=0, length=0, list=0;
	numx *fir;
	node** head;
	bool error=0;
	char **order=(char**)malloc(sizeof(char*)*10000);
	while(1){
		order[length]=(char*)malloc(sizeof(char)*3);
		scanf("%s", &order[length]);
		if(order[length][0]=="Q"){
			break;
		}else if (order[length][0]=="N"){
			scanf("%d", &i);
			fir=insert(fir, i);
		}
		length++;
	}
	scanf("%d", &i);
	head=(node**)malloc(sizeof(node*)*i);
	for (j=0; j<i; j++){
		head[j]=(node*)malloc(sizeof(node));
		scanf("%d", &count);
		head[j]->num=count;
	}
	count=0;
	for (i=0; i<list; i++){
		for(j=0; j<length; j++){
			//명령문 판독
			if (order[j][0]=="N"){
				if (0<=fir->num<=pow(10, 9)){
					head[i]=num(head[i], del(fir));
					count++;
				}else{
					error=1;
					break;
				}
			}else if(order[j][0]=="P"){
				if (count<0){
					error=1;
					break;
				}
				head[i]=pop(head[i]);
				count--;
			}else if(order[j][0]=="I"){
				inv(head[i]);
			}else if(order[j][0]=="D"){
				if (order[j][1]=="U"){
					head[i]=num(head[i], head[i]->num);
					count++;
				}
			}else{
				if (count>1){
					if(order[j][0]=="S"){
						if (order[j][1]=="W"){
							swp(head[i]);
						}else{
							head[i]=sub(head[i]);
							count--;	
						}
					}else if(order[j][0]=="A"){
						head[i]=add(head[i]);
						count--;
					}else if (head[i]->num==0){
						error=1;
						break;
					}else if(order[j][0]=="D"){
						head[i]=_div(head[i]);
						count--;
					}else if(order[j][0]=="M"){
						head[i]=mod(head[i]);
						count--;
					}else{
						error=1;
						break;
					}
				}else{
					error=1;
					break;
				}
			}
			//error 걸러내기
			if (error || head[i]->num>=(pow(10, 9)) || head[i]->num<=(-1)*(pow(10, 9)) || count<1 || count>1){
				printf("ERROR");
				continue;
			}
		}
	}
	return 0;
}