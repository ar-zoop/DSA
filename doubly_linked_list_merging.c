
// merging 2 double linked lists.
// mergine 2nd list into 1st list. assuming both are sorted, end result must also be sorted
#include <stdio.h>
#include <stdlib.h>

typedef struct link_node
{
  struct link_node *left;
  int data;
  struct link_node *right;
} node;

node *ptr1 = NULL, *ptr2 = NULL;
int createList(node *, int);
int merge(node*, node*);
void display(node *);

int main()
{
  
  ptr1=createList(ptr1, 1);
  ptr2=createList(ptr2, 2);
  node *ptr3=merge(ptr1,ptr2);
  display(ptr3);
//  display(ptr2);
  
  return 0;
}

int createList(node *root, int i)
{
  int t = 5;
  node *temp2 = NULL;
  while (t--)
  {
    //  printf("start ");

    node *temp = (node *)malloc(sizeof(node));
    if (root == NULL)
    {
      root = temp2 = temp;
      temp->left = temp->right = NULL;
      temp->data = i;
      
    }
    else
    {
      i += 2;
      temp->data = i;
      temp->right = NULL;
      temp2->right = temp;
      temp->left = temp2;
      temp2 = temp;
//         printf("%d ",temp->data);
    }

    // printf("end \n");
  }
  return root;
}

void display(node *temp)
{
//  	printf("hiii");

  while (temp != NULL)
  {
//  	printf("hiii");
    printf("%d ", temp->data);
    temp = temp->right;
  }
  printf("\n");
}

int merge(node *a, node *b){
	node *start,*temp1,*temp2,*temp;
	if(a->data>b->data){
		start=b;
	}
	else{
		start=a;
	}
	temp1=a;
	temp2=b;
	do{
		if(temp1->data>temp2->data){
			temp=temp2->right;
			temp2->right=temp1;
			temp1->left=temp2;
			temp2=temp;
		}
		else{
			temp=temp1->right;
			temp1->right=temp2;
			temp2->left=temp1;
			temp1=temp;
		}
	}while(temp1!=NULL && temp2!=NULL);
	
	return start;
}
