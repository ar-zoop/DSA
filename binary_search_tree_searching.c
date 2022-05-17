#include <stdio.h>

typedef struct bst_node{
	struct bst_node *left;
	int data;	
	struct bst_node *right;
}node;

void search();
int search_recur(int, node*);
void insert();

node *root, *temp,*p,*q;

int main(){
	insert();
	search();
	int num;
	printf("Enter the number you want to search: ");
	scanf("%d", &num);
	p=root;
	search_recur(int num, node* p);
	
	return 0;
}


void insert(){
	int n;
	printf("Enter no. of nodes in tree: ") ;
	scanf("%d", &n);
	while(n){
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
    	--n;
		}
	
  	}
  
}

//ALTERNATE WAY 1 : using recursion

int search_recur(int num, node* p){	
	if (p==NULL){
		printf("tree is empty.\n");
		return;
	}
	else{
	
		while(p!=NULL){
			if (p->data==num){
			//element found condition
				printf("Element found\n");
				return ;
			}
			else if (p->data > num){
//				p=p->left;
				return (num, p->left);
			}
			else {
				return (num, p->right);
//				p=p->right;
			}	
		
		}	
	}
}

//ALTERNATE WAY 2 : without using flag
/*
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


//ALTERNATE WAY 3 : with using flag
/* void search(){
	
	int num, flag =0;
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
				flag = 1;
				break;
			}
			else if (p->data > num){
				p=p->left;
			}
			else {
				p=p->right;
			}	
		}
		
		if (flag==0){
			printf("NOT FOUND \n"); 
		}
		else{
			printf("FOUND \n");
		}
	
	}
}
*/

