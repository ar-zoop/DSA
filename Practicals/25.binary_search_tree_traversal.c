#include<stdio.h>
#include <stdlib.h>
typedef struct bst_node{
	struct bst_node *left;
	int data;
	struct bst_node *right;
}node;

node *root,*temp,*p,*q;

void insert(int);
void inorder(node *);
void preorder(node *);
void postorder(node *);

int main(){
	int n;
	printf("Enter no. of nodes you want in the tree: ");
	scanf("%d", &n);
	insert(n);
	printf("Your choices are: \n1)Inorder\n2)Postorder\n3)Preorder: ");
	while(1){
		scanf("%d",&n);
		switch(n){
			case 1: inorder(root);break;
			case 2: postorder(root);break;
			case 3:preorder(root);break;
			default: printf("Invalid choice!");
		}
	}
	return 0;
}

void insert(int n){
	while(n--){
		temp=(node*)malloc(sizeof(node));
		printf("Enter the value: ");
		scanf("%d", &temp->data);
		temp->left=temp->right=NULL;
		if(root==NULL){
			root=temp;
			
		}
		else{
			p=root;
			while(p!=NULL){
				if(temp->data>p->data){
					q=p;
					p=p->right;
				}
				else{
					q=p;
					p=p->left;
				}
			}
			if(temp->data>q->data){
				q->right=temp;
			}
			else{
				q->left=temp;
			}
		}
	}
}

void inorder(node *temp){
	p=root;
	if(temp==NULL)
		return;
	
	inorder(temp->left);
	printf("%d ",temp->data);
	inorder(temp->right);
}

void preorder(node *temp){
	p=root;
	if(temp==NULL)
		return;
	printf("%d ",temp->data);
	preorder(temp->left);
	
	preorder(temp->right);
}

void postorder(node *temp){
	p=root;
	if(temp==NULL)
		return;
	
	postorder(temp->left);
	
	postorder(temp->right);
	printf("%d ",temp->data);
}

