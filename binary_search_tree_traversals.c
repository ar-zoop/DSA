#include <stdio.h>

typedef struct bst_node{
	struct bst_node *left;
	int data;	
	struct bst_node *right;
}node;

void insert();
int inorder(node*);

node *root, *temp,*p,*q;

int main(){
	insert();
	inorder(root);
	return 0;
}


void insert(){
	int n;
	printf("Enter no. of nodes in tree: ") ;
	scanf("%d", &n);
	while(n--){
	  	temp=(node*)malloc(sizeof(node));
	  	printf("Enter data: ");
	  	scanf("%d", &temp->data);
	  	temp->right=NULL;
	  	temp->left=NULL;
	  	if(root==NULL){
	    	root=temp;
	  	}
	  	else{
	  		p=root;	
	  		while(p!=NULL){
		      if (temp->data>p->data){
				q=p;
				p=p->right;
		      }
		      else{
		        q=p;
		        p=p->left;
		      }
	
			}
		    if (temp->data>q->data){
	        	q->right=temp;
			}
			else {
				q->left=temp;
			}
    	
		}
	
  	}
  
}

int inorder(node* temp){
	p=root;
	if (temp==NULL){
		return ;
	}
	inorder(temp->left);
	printf("%d ",temp->data);
	inorder(temp->right);
	
}
