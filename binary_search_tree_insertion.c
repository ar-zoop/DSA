#include <stdio.h>


typedef struct bst_node{
  struct bst_node *left;
  int data;  
  struct bst_node *right;
}node;

node *root, *temp;
node *p, *q;

int main(){
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
//	        printf("5");
//	        printf("\n---%d---\n",q->data);
	      }
	      else{
	        q=p;
	        p=p->left;
//	        printf("6");
//	        printf("\n---%d---\n",q->data);
	      }
//	      printf("00");
		}
	    if (temp->data>q->data){
        	q->right=temp;
//        	printf('7');
		}
		else {
			q->left=temp;
//			printf('8');	
		}
    	--n;
		}
	
  }
  
  return 0;
}


