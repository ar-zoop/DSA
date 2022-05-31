#include<stdio.h>
#include <stdlib.h>
typedef struct bst_node{
	struct bst_noes *left;
	int data;
	struct bst_noes *right;
}node;

node *root,*temp,*p,*q;

void insert(int);
void search(int);

int main(){
	int n;
	printf("Enter no. of nodes you want in the tree: ");
	scanf("%d", &n);
	insert(n);
	printf("\n Enter the node you want to search: ");
	scanf("%d",&n);
	search(n);
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
void search(int data){
		if(root==NULL){
			printf("Underflow");			
		}
		else{
			p=root;
			while(p!=NULL){
				if(p->data==data){
					printf("Found");
					break;
				}
					
				else if(data>p->data){
//					q=p;
					p=p->right;
				}
				else{
//					q=p;
					p=p->left;
				}
			}
		
				
			if(p==NULL){
				printf("NOt found");
			}
		}
}
