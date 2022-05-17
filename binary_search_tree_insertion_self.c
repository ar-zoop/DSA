#include <stdio.h>

void create_node();
void insert();


typedef struct bst_node{
	struct bst_node *left;
	int data;	
	struct bst_node *right;
}node;

node *root, *temp;

int main(){
	insert();	
	insert();
	insert();
	insert();
	insert();
	insert();
	return 0;
}

void create_node(){
	
//	printf("2");
}

void insert(){
	printf("3");
	printf("1");
	temp=(node*)malloc(sizeof(node));
	if(root==NULL){
		root=temp;
		root->left=NULL;
		root->right=NULL;
	}
	printf("Enter data: ");
	scanf("%d", &temp->data);
	if (temp==root){
		printf("4");
		}
	else{
		node *p, *q;
		p=root;
		while(p!=NULL){
			if (temp->data > p->data){
				q=p;
				p=p->right;
//				printf("5");
			}
			else{
				q=p;
				p=p->left;
//				printf("6");
			}
		}
		if (p==NULL){
			if (temp->data > q->data){
				q->right = temp;
//				printf('7');
			}
			else {
				q->left = temp;
//				printf('8');
			}
		}
	}-
	printf("7\n");
}
