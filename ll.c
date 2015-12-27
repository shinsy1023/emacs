#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
  int num;
  struct _node *next;
}node;

node* add(node* head, int num){
  if(head==NULL){
    head=(node*)malloc(sizeof(node));
    head->num=num;
    return head;
  }
  node* tmp=head;
  while (tmp->next!=NULL){
    tmp=tmp->next;
  }
  tmp->next=(node*)malloc(sizeof(node));
  tmp->next->num=num;
  return head;
}
 
void print(node* head){
  while(head->next!=NULL){
    printf("%d->", head->num);
    head=head->next;
  }
}

int main(){
  node* head;
  printf("%x\n", &head);
  /* add(head, 1); */
  /* add(head, 2); */
  /* add(head, 3); */
  /* add(head, 4); */
  /* print(head) */;
  return 0;
}
