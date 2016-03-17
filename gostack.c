#include <stdio.h>
#include <stdlib.h>

struct node{
	int num;
	node* stack;
};

node* num(node* head, int num);
node* pop(node* head);
void inv(node* head);
void swp(node* head);
node* add(node* head);
node* sub(node* head);
node* mul(node* head);
node* div(node* head);
node* mod(node* head);

node* num(node* head, int num){
	node* top=(node*)malloc(sizeof(node));
	top->num=num;
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

// node* DUP(node* head){
// 	node* tmp=(node*)malloc(sizeof(node));
// 	tmp->num=head->num;
// 	tmp->stack=head;
// 	return tmp;
// }

void swp(node* head){
	int tmp=head->stack->num;
	head->stack->num=head->num;
	head->num=tmp;
}

node* add(node* head){
	node* tmp=head->stack;
	tmp->num=head->num+tmp->num;
	if (0<tmp->num && tmp->num<10**9){
		head=NULL;
		return tmp;
	}else{
		error=1;
		return NULL;//main 함수에서 add sub mul 등등 함수 실행 뒤 head->num의 범위 판정해서 에러인지 아닌지 판별하기
	}
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

node* div(node* head){
	node* tmp=head->stack;
	tmp->num=int(tmp->num/head->num);
	head=NULL;
	return tmp;
}

node* mod(node* head){
	node* tmp=head->stack;
	tmp->num=tmp->num%head->num;
	head=NULL;
	return tmp;
}

int main(int argc, char const *argv[]){
	int i=0, count=0, length=0;
	node* head;
	bool error=0;
	char **order=(char**)malloc(sizeof(char*)*10000);
	while(1){
		order[length]=(char*)malloc(sizeof(char)*3);
		scanf("%s", &order[count]);
		if(order[length][0]=="Q"){
			break;
		}
		length++;
	}
	for(i=0; i<length; i++){
		if (order[count][0]=="N"){
			int num;
			scanf("%d", &num);
			if (0<=num<=10**9){
				head=num(head, num);
				count++;
			}else{
				error=1;
				break;
			}
		}else if(order[count][0]=="P"){
			if (count<0){
				error=1;
				break;
			}
			head=pop(head);
			count--;
		}else if(order[count][0]=="I"){
			inv(head);
		}else if(order[count][0]=="D"){
			if (order[count][1]=="U"){
				head=num(head, head->num);
				count++;
			}
		}else{
			if (count>1){
				if(order[count][0]=="S"){
					if (order[count][1]=="W"){
						swp(head);
					}else{
						head=sub(head);
						count--;	
					}
				}else if(order[count][0]=="A"){
					head=add(head);
					count--;
				}else if (head->num==0){
					error=1;
					break;
				}else if(order[count][0]=="D"){
					head=div(head);
					count--;
				}else if(order[count][0]=="M"){
					head=mod(head);
					count--;
				}else{
					error=1;
					break;
				}
			}
		}
		if (head->num>=(10**9) || head->num<=(-1)*(10**9)){
			error=1;
			break;
		}
	}
	if (error){
		printf("ERROR");
		return 0;
	}
	return 0;
}