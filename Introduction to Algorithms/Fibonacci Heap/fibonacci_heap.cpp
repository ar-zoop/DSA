#include <bits/stdc++.h>
using  namespace std;

typedef struct fibheapNode{
    struct fibheapNode *child;
    struct fibheapNode *left;
    struct fibheapNode *right;
    struct fibheapNode *parent;
    int key;
    int degree;
    bool marked;
}node;

class fibheap{
    public:
    node *rootlist;
    node *min;
    int n;
public:
    fibheap(){
        rootlist=NULL;
        min = NULL;
        n=0;
    }
};

node* create_node(int key){
    node *temp=new node;
    temp->child=NULL;
    temp->parent = NULL;
    temp->left = NULL;
    temp->right = NULL;
    temp->key=key;
    temp->marked= false;
    temp->degree=0;
    return temp;
}

int get_min(fibheap FH){
    cout<<(FH.min)->key<<endl;
}

void merge_with_rootlist(node *&node, fibheap &FH){
    if(node==NULL) return;
    if(FH.rootlist==NULL){
        FH.rootlist=node;
    }
    else{
        node->right=(FH.rootlist)->right;
        (FH.rootlist)->right=node;
        node->right->left=node;
        node->left=FH.rootlist;
    }
}

void insert(int key, fibheap &FH){
    node *node= create_node(key);
    node->left=node;
    node->right=node;
    merge_with_rootlist(node, FH);
    if(FH.min==NULL || (FH.min)->key> node->key){
        FH.min= node;
    }
    FH.n++;
    return;
}

fibheap _union(fibheap& H1, fibheap &H2){
    fibheap FH;
    FH.rootlist=H1.rootlist;
    if(H1.min<H2.min){
        FH.min=H1.min;
    }
    else{
        FH.min=H2.min;
    }
    node *H1lastnode= (H1.rootlist)->left;
    H1lastnode->right = H2.rootlist;
    (H1.rootlist)->left = (H2.rootlist)->left;
    ((H1.rootlist)->left)->right= H1.rootlist;
    (H1lastnode->right)->left=H1lastnode;
    FH.n=H1.n+H2.n;
    free(H1.rootlist);
    free(H2.rootlist);
    H1.min = NULL;
    H1.rootlist=NULL;
    H2.min = NULL;
    H2.rootlist = NULL;
    return FH;
}

void fibheap_link(node *&destination, node *&source){
    
    (source->left)->right=source->right;
    (source->right)->left=source->left;
    source->left=destination->left;
    destination->left=source;
    (source->left)->right=source;
    destination->left=source;
    (source->left)->right=source;
    source->right=destination;
    return ;
}

void remove_nodes(fibheap &FH){
    if(FH.min==FH.rootlist){
        FH.rootlist=(FH.rootlist)->right;
    }
    ((FH.min)->left)->right=(FH.min)->right;
    ((FH.min)->right)->left=(FH.min)->left;
    free(FH.min);
    FH.min=NULL;
    FH.n--;
    return;
}

void remove_nodes(fibheap &FH, node *&min)
{
    if (min == FH.rootlist)
    {
        FH.rootlist = (FH.rootlist)->right;
    }
    ((min)->left)->right = (min)->right;
    ((min)->right)->left = (min)->left;
    FH.n--;
    return;
}

void extract_min(fibheap &FH){
    node *orphan_nodes=(FH.min)->child;
    // if(orphan_nodes==NULL)cout<<"NULL";
    merge_with_rootlist(orphan_nodes, FH);    
    remove_nodes(FH);
    node *arr[FH.n]={NULL};
    node *i=FH.rootlist;
    FH.min=FH.rootlist;
    do{
        if(arr[i->degree]==NULL){
            arr[i->degree]=i;            
            i=i->right;       
        }
        else{
            cout<<"hi";
            /*
            int n=i->degree;
            node *x=arr[n];
            node *y=i;
            if(y->key < x->key){
                swap(x,y);
            }
            node *child_rootlist=x->child;
            remove_nodes(FH, y);
            if(child_rootlist==NULL){
                fibheap_link(child_rootlist,y);
                x->degree++;
            }
            else{
                x->child=y;
            }
            arr[n]=NULL;
            i=x;
            */
        }
        if(i->key<(FH.min)->key){
            FH.min=i;
        }
       
    }while(i!=FH.rootlist);
   
}

int main(){
    fibheap FH1;
    insert(10,FH1);
    get_min(FH1);
    insert(20,FH1);
    get_min(FH1);
    insert(5,FH1);
    get_min(FH1);
    fibheap FH2;
    insert(100, FH2);
    get_min(FH2);
    insert(200, FH2);
    get_min(FH2);
    insert(50, FH2);
    get_min(FH2);
    extract_min(FH1);
    /*
    get_min(FH1);
    fibheap FH;
    FH= _union(FH1, FH2);
    get_min(FH);
    insert(1, FH);
    get_min(FH);
    // get_min(FH);
*/

possible errors: extract min -> part in /* */. Rootlist is not being managed to take care when y is rootlist.
merge_with_rootlist: -> the linking is not proper. The starting is not being connected to the las node of the new node list.
    return 0;
} 