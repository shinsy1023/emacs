typedef struct node{
	int val;
	struct node* next;
}node;

node* newnode(int n){
	node* temp = (node*)malloc(sizeof(node));
	temp->val = n;
	temp->next = NULL;
	return temp;
}