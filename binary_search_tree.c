#include <stdio.h>
//creation of bs tree
void insert();

typedef struct bst_node{
	struct bst_node *left;
	int data;	
	struct bst_node *right;
}node;

node *root, *temp,*p,*q;

int main(){
	insert();	

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

void search(){
	
	
	int num;
	printf("Enter the number you want to search: ");
	scanf("%d", &num);
	p=root;
	
	if (p==NULL){
		printf("tree is empty.\n");
	}
	else{
	
		while(p!=NULL){
			if (p->data==num){
			//element found condition
				printf("Element found\n");
				break;
			}
			else if (p->data > num){
				p=p->left;
			}
			else {
				p=p->right;
			}	
		
		}
		if (p==NULL)
			printf("Element not found. \n");
		
	
	
	}
}
