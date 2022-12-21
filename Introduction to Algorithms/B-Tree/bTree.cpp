#include <bits/stdc++.h>
using  namespace std;

const int m=2;

typedef struct BTreeNode{
    int *key = new int(m);
    BTreeNode *child[m + 2];
    int numKeys;
    bool isLeaf;
    BTreeNode *parent;

}node;

node *root;

node* create_node(){
    node* new_node=new node;
    new_node->numKeys=0;
    new_node->isLeaf=true;
    new_node->parent=NULL;
    return new_node;
    
}

int split(node *&ogNode, int key, node *&newNode)
{
    // step 1: create a new node jisme median key ke baad ke elements aaengey kyuki udar split hoga.
    // receievd form arguemnts
    // step 2: calculate the median key
    int medianKey = ogNode->numKeys / 2;
    // step 3: copy the elemnts after the mediankey into the new nodes key array
    for (int i = medianKey + 1; i < (ogNode->numKeys); i++)
    {
        newNode->key[i - medianKey - 1] = ogNode->key[i];
        newNode->child[i - medianKey - 1] = ogNode->child[i];
    }
    newNode->child[(ogNode->numKeys) - 1] = ogNode->child[(ogNode->numKeys) - 1]; // this copies the last child pointer which was not covered in the for loop

    // step 4: update the numkeys for new node and og node
    newNode->numKeys = ogNode->numKeys - medianKey - 1;
    ogNode->numKeys = medianKey;
    // step 5: update ognode to the new node and return in it to the parent. return the mediankey as the new key
    return medianKey;
}

node* insert_non_full(node *&Node, int key){
    //insertion in a non full node
    int i=Node->numKeys-1;
    while(Node->key[i]>key){
        Node->key[i+1]=Node->key[i];
        i--;
    }
    i++;
    Node->key[i]=key;
    Node->numKeys++;
    return Node;
}

node* insert(node *&Node, node *&child, int key){
    //if numsKey!=Max
    // cout<<"hi";
    if (root == NULL)
    {
        root = create_node();
        root->key[0] = key;
        root->numKeys = 1;
    }
    else if(Node->numKeys==m){
        node *medianChild= new node;
        medianChild->parent=Node;
        int medianKey=Node->numKeys/2;
        split(Node, key, medianChild);
        if(root==Node){
            node *new_node= create_node();
            new_node->key[0]=medianKey;
            new_node->numKeys=1;
            new_node->child[0]=Node;
            new_node->child[1]=medianChild;
            new_node->isLeaf=false;
        }
        else{
            insert(Node->parent, medianChild, medianKey);
        }
    }
    else{
        insert_non_full(Node, key);
    
    }
    return Node;

}


bool search(node *x, int key){
    int i=0;
    while(i<m && key>x->key[i])i++;
    if(i<=m && key==x->key[i]) return true;
    else if(x->isLeaf) return false;
    else return (x->child[i],key);
}

int main(){
    node * Node= (node*)malloc(sizeof(node));
    node *Child = (node *)malloc(sizeof(node));
    insert(root, Child,1);
    insert(root, Child, 2);
    insert(root, Child, 3);
    insert(root, Child, 4);
    insert(root, Child, 5);
    // cout<<search(root,10)<<endl;
    cout << search(root, 1);
    // cout << search(root, 1);
    // cout << search(root, 99);
    cout << search(root, 2);
    cout << search(root, 3);
    cout << search(root, 4);
    cout << search(root, 5);
    return 0;

} 