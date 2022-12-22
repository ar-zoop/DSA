#include <bits/stdc++.h>
using  namespace std;

const int m=2;
const int minKeys=ceil(m/2);

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


node* search(node *x, int key){
    int i=0;
    while(i<m && key>x->key[i])i++;
    if(i<=m && key==x->key[i]) return x;
    else if(x->isLeaf) return NULL;
    else search(x->child[i],key);
}

bool pred(node *&parent, int key){
    int i;
    for(i=0; i<parent->numKeys; i++){
        if(key==parent->key[i]){
            break;
        }
    }
    node *childNode=parent->child[i];
    if(childNode->numKeys>minKeys){
        int predKey=childNode->key[(childNode->numKeys)-1];
        parent->key[i]=predKey;
        childNode->numKeys--;
        return true;}
    return false;
}

bool succ(node *&parent, int key)
{
    int i;
    for (i = 0; i < parent->numKeys; i++)
    {
        if (key == parent->key[i])
        {
            break;
        }
    }
    node *childNode = parent->child[i+1];
    if (childNode->numKeys > minKeys)
    {
        int succKey = childNode->key[0];
        parent->key[i] = succKey;
        childNode->numKeys--;
        return true;
    }
    return false;
}

//delete fixup
void delete_key(node *nodeToDelete, int key){
    node *parent = nodeToDelete->parent;
    int i;
    for (i = 0; i < parent->numKeys; i++)
    {
        if (parent->key[i] > key)
            break;
    }
    int rightChildPointer = i + 1;
    node *rightSibling = NULL;
    node *leftSibling = NULL;
    if (rightChildPointer < parent->numKeys)
        rightSibling = parent->child[rightChildPointer];
    int childPointer = i - 1;
    int leftChildPointer = i - 2;
    if (leftChildPointer >= 0)
        leftSibling = parent->child[leftChildPointer];
    int maxKey = leftSibling->key[(leftSibling->numKeys) - 1];
    int minKey = rightSibling->key[0];
    // CASE 2: left sibling has numkeys>min
    if (leftSibling->numKeys > minKeys)
    {
        int parentKey = parent->key[leftChildPointer];
        parent->key[leftChildPointer] = maxKey;
        parent->key[childPointer]=leftSibling->key[leftSibling->numKeys-1];
        nodeToDelete->child[nodeToDelete->numKeys + 1] = nodeToDelete->child[nodeToDelete->numKeys];
        for (int i = nodeToDelete->numKeys - 1; i >=0 ; i--)
        {
            nodeToDelete->key[i+1]=nodeToDelete->key[i];
            nodeToDelete->child[i+1]=nodeToDelete->child[i];   
        }
        nodeToDelete->key[0]=parentKey;
        nodeToDelete->child[0]=leftSibling->child[leftSibling->numKeys];
        leftSibling->numKeys--;
        // int prev = maxKey, curr = nodeToDelete->key[0];

       

    }
    // CASE 3: right sibling has numkeys>min
    else if (rightSibling->numKeys > minKeys)
    {
        int parentKey = parent->key[rightChildPointer];
        parent->key[rightChildPointer] = maxKey;
        parent->key[childPointer] = rightSibling->key[rightSibling->numKeys - 1];
        nodeToDelete->child[nodeToDelete->numKeys + 1] = nodeToDelete->child[nodeToDelete->numKeys];
        for (int i = nodeToDelete->numKeys - 1; i >= 0; i--)
        {
            nodeToDelete->key[i + 1] = nodeToDelete->key[i];
            nodeToDelete->child[i + 1] = nodeToDelete->child[i];
        }
        nodeToDelete->key[0] = parentKey;
        nodeToDelete->child[0] = rightSibling->child[rightSibling->numKeys];
        rightSibling->numKeys--;
    }
    //merge
    else{        
            if (leftSibling)
            {
                // copying leftchild keys into nodeToDelete keys.
                // int j = 0;
                // for (int i = nodeToDelete->numKeys; i < m; i++)
                // {
                //     nodeToDelete->key[i] = leftSibling->key[j];
                //     j++;
                // }
                // // sort(nodeToDelete->key, nodeToDelete->key + m);
            int j = nodeToDelete->numKeys + leftSibling->numKeys -2;
            nodeToDelete->child[j + 1] = nodeToDelete->child[nodeToDelete->numKeys];
            for (int i = nodeToDelete->numKeys; i >= 0; i--)
            {
                nodeToDelete->key[j] = nodeToDelete->key[i];
                nodeToDelete->child[j] = nodeToDelete->child[i];
                j--;
            }
            for (int i = 0; i < leftSibling->numKeys; i++){
                nodeToDelete->child[i]=leftSibling->child[i];
                nodeToDelete->key[i]=leftSibling->key[i];
            }
                nodeToDelete->child[nodeToDelete->numKeys] = leftSibling->child[leftSibling->numKeys];
                nodeToDelete->numKeys += leftSibling->numKeys;
                // replace the keyToDelete with the parents key
                int i;
                for (i = 0; i < parent->numKeys; i++)
                {
                    if (parent->key[i] > key)
                    {
                        break;
                    }
                }
                int parentKeyPos = i - 1;
                for (int i = 0; i < nodeToDelete->numKeys; i++)
                {
                    if (nodeToDelete->key[i] == key)
                    {
                        nodeToDelete->key[i] = parent->key[parentKeyPos];
                    }
                }
                // making shifts for the deleted key
                for (int i = parentKeyPos; i < parent->numKeys - 1; i++)
                {
                    parent->key[i] = parent->key[i + 1];
                    // parent->child[i]=parent->child[i+1];
                }
                for (int i = parentKeyPos + 1; i < parent->numKeys; i++)
                {
                    parent->child[i] = parent->child[i + 1];
                }
                parent->numKeys--;
                free(leftSibling);
                leftChildPointer = NULL;
            }
            else
            {
                // copying rightchild keys into nodeToDelete keys.
                int j = nodeToDelete->numKeys + rightSibling->numKeys - 2;
                nodeToDelete->child[j + 1] = nodeToDelete->child[nodeToDelete->numKeys];
                for (int i = nodeToDelete->numKeys; i >= 0; i--)
                {
                    nodeToDelete->key[j] = nodeToDelete->key[i];
                    nodeToDelete->child[j] = nodeToDelete->child[i];
                    j--;
                }
                for (int i = 0; i < rightSibling->numKeys; i++)
                {
                    nodeToDelete->child[i] = rightSibling->child[i];
                    nodeToDelete->key[i] = right`Sibling->key[i];
                }
                nodeToDelete->numKeys += rightSibling->numKeys;
                // replace the keyToDelete with the parents key
                int i;
                for (i = 0; i < parent->numKeys; i++)
                {
                    if (parent->key[i] > key)
                    {
                        break;
                    }
                }
                int parentKeyPos = i;
                for (int i = 0; i < nodeToDelete->numKeys; i++)
                {
                    if (nodeToDelete->key[i] == key)
                    {
                        nodeToDelete->key[i] = parent->key[parentKeyPos];
                        break;
                    }
                }
                // shifting due to the deleted key in the parent node
                for (int i = parentKeyPos; i < parent->numKeys - 1; i++)
                {
                    parent->key[i] = parent->key[i + 1];
                    // parent->child[i] = parent->child[i + 1];
                }
                for (int i = parentKeyPos + 1; i < parent->numKeys; i++)
                {
                    parent->child[i] = parent->child[i + 1];
                }
                parent->numKeys--;
                free(rightSibling);
                rightChildPointer = NULL;
            }
    }
}


//remove
void delete_key(int key){
    if(!root){
        return;
    }
    if(node* nodeToDelete= search(root,key)){
        //if the node is a leaf node
        //Leaf node deletion
        if(nodeToDelete->isLeaf){
            // CASE 1: if the node has numKeys>min
            if(nodeToDelete->numKeys>minKeys){
                //deletion by shifting
                int i;
                for(i=0;i<nodeToDelete->numKeys; i++){
                    if(nodeToDelete->key[i]==key){
                        break;
                    }
                }
                for(int j=i; j<nodeToDelete->numKeys; j++){
                    nodeToDelete->key[i]=nodeToDelete->key[i+1];
                }
                nodeToDelete->numKeys--;
            }

            else{
                node *parent=nodeToDelete->parent;
                int i;
                for(i=0; i<parent->numKeys; i++){
                    if(parent->key[i]>key)break;
                }
                int rightChildPointer=i+1;
                node *rightSibling=NULL;
                node *leftSibling=NULL;
                if (rightChildPointer < parent->numKeys)
                    rightSibling = parent->child[rightChildPointer];
                int childPointer=i-1;
                int leftChildPointer=i-2;
                if (leftChildPointer >=0)
                    leftSibling = parent->child[leftChildPointer];
                int maxKey= leftSibling->key[(leftSibling->numKeys)-1];
                int minKey = rightSibling->key[0];
                //CASE 2: left sibling has numkeys>min
                if(leftSibling->numKeys>minKeys){
                    int parentKey = parent->key[leftChildPointer];
                    parent->key[leftChildPointer] = maxKey;
                    leftSibling->numKeys--;
                    int prev = maxKey, curr = nodeToDelete->key[0];
                    for(int i=0; i<nodeToDelete->numKeys; i++){
                        curr = nodeToDelete->key[i];
                        nodeToDelete->key[i] = prev;
                        prev=curr;
                        if(prev==key){
                            break;
                        }
                    }
                }
                // CASE 3: right sibling has numkeys>min
                else if(rightSibling->numKeys>minKeys){
                    
                    int parentKey = parent->key[rightChildPointer];
                    parent->key[rightChildPointer] = minKey;
                    rightSibling->numKeys--;
                    int next = minKey, curr = nodeToDelete->key[0];
                    for (int i = nodeToDelete->numKeys-1; i >=0; i--)
                    {
                        curr = nodeToDelete->key[i];
                        nodeToDelete->key[i] = next;
                        next = curr;
                        if (next == key)
                        {
                            break;
                        }
                    }
                }
                // CASE 4: merge
                else{
                    if(leftSibling){
                        //copying leftchild keys into nodeToDelete keys.
                        for (int i = nodeToDelete->numKeys; i >= 0; i--)
                        {
                            nodeToDelete->key[j] = nodeToDelete->key[i];
                            nodeToDelete->child[j] = nodeToDelete->child[i];
                            j--;
                        }
                        for (int i = 0; i < leftSibling->numKeys; i++){
                            nodeToDelete->child[i]=leftSibling->child[i];
                            nodeToDelete->key[i]=leftSibling->key[i];
                        }
                        // replace the keyToDelete with the parents key
                        int i;
                        for(i=0; i<parent->numKeys; i++){
                            if(parent->key[i]>key){
                                break;
                            }
                        }
                        int parentKeyPos=i-1;
                        for (int i = 0; i < nodeToDelete->numKeys; i++){
                            if (nodeToDelete->key[i]==key){
                                nodeToDelete->key[i] = parent->key[parentKeyPos];
                            }
                        }
                        //making shifts for the deleted key
                        for (int i = parentKeyPos; i<parent->numKeys-1; i++){
                            parent->key[i]=parent->key[i+1];
                            // parent->child[i]=parent->child[i+1];
                        }
                        for (int i = parentKeyPos + 1; i < parent->numKeys; i++)
                        {
                            parent->child[i] = parent->child[i + 1];
                        }
                        parent->numKeys--;
                        free(leftSibling);
                        leftChildPointer=NULL;
                    }
                    else{
                        // copying rightchild keys into nodeToDelete keys.
                        int j = nodeToDelete->numKeys + rightSibling->numKeys - 2;
                        nodeToDelete->child[j + 1] = nodeToDelete->child[nodeToDelete->numKeys];
                        for (int i = nodeToDelete->numKeys; i >= 0; i--)
                        {
                            nodeToDelete->key[j] = nodeToDelete->key[i];
                            nodeToDelete->child[j] = nodeToDelete->child[i];
                            j--;
                        }
                        for (int i = 0; i < rightSibling->numKeys; i++)
                        {
                            nodeToDelete->child[i] = rightSibling->child[i];
                            nodeToDelete->key[i] = rightSibling->key[i];
                        }
                        // replace the keyToDelete with the parents key
                        int i;
                        for (i = 0; i < parent->numKeys; i++)
                        {
                            if (parent->key[i] > key)
                            {
                                break;
                            }
                        }
                        int parentKeyPos = i;
                        for (int i = 0; i < nodeToDelete->numKeys; i++)
                        {
                            if (nodeToDelete->key[i] == key)
                            {
                                nodeToDelete->key[i] = parent->key[parentKeyPos];
                                break;
                            }
                        }
                        //shifting due to the deleted key in the parent node
                        for (int i = parentKeyPos; i < parent->numKeys - 1; i++)
                        {
                            parent->key[i] = parent->key[i + 1];
                            // parent->child[i] = parent->child[i + 1];
                        }
                        for (int i = parentKeyPos + 1; i < parent->numKeys; i++){
                            parent->child[i] = parent->child[i + 1];
                        }
                        parent->numKeys--;
                        free(rightSibling);
                        rightChildPointer = NULL;
                    }
                    //fixup the parent
                    delete_key(parent, key);
                }
            }
        }
        //Internal Node Deletion
        else{
            node *parent = nodeToDelete->parent;
            int i;
            for (i = 0; i < parent->numKeys; i++)
            {
                if (parent->key[i] > key)
                    break;
            }
            int rightChildPointer = i + 1;
            node *rightSibling = NULL;
            node *leftSibling = NULL;
            if (rightChildPointer < parent->numKeys)
                rightSibling = parent->child[rightChildPointer];
            int childPointer = i - 1;
            int leftChildPointer = i - 2;
            if (leftChildPointer >= 0)
                leftSibling = parent->child[leftChildPointer];
            int maxKey = leftSibling->key[(leftSibling->numKeys) - 1];
            int minKey = rightSibling->key[0];
            //find inorder predecessor
            if(pred(nodeToDelete, key)){
                for(int i=0; i<nodeToDelete->numKeys; i++){
                    if(key>nodeToDelete->key[i]){
                        key=nodeToDelete->key[i-1];
                        break;
                    }

                }
            }
            //find inorder successor
            else if (succ(nodeToDelete, key)){
                for (int i = 0; i < nodeToDelete->numKeys; i++)
                {
                    if (key > nodeToDelete->key[i])
                    {
                        key = nodeToDelete->key[i];
                        break;
                    }
                }
            }

            //merge
            else{
                if (leftSibling)
                {
                    // copying leftchild keys into nodeToDelete keys.
                    int j = 0;
                    for (int i = nodeToDelete->numKeys; i < m; i++)
                    {
                        nodeToDelete->key[i] = leftSibling->key[j];
                        j++;
                    }
                    sort(nodeToDelete->key, nodeToDelete->key + m);
                    nodeToDelete->numKeys += leftSibling->numKeys;
                    // replace the keyToDelete with the parents key
                    int i;
                    for (i = 0; i < parent->numKeys; i++)
                    {
                        if (parent->key[i] > key)
                        {
                            break;
                        }
                    }
                    int parentKeyPos = i - 1;
                    for (int i = 0; i < nodeToDelete->numKeys; i++)
                    {
                        if (nodeToDelete->key[i] == key)
                        {
                            nodeToDelete->key[i] = parent->key[parentKeyPos];
                        }
                    }
                    // making shifts for the deleted key
                    for (int i = parentKeyPos; i < parent->numKeys - 1; i++)
                    {
                        parent->key[i] = parent->key[i + 1];
                        // parent->child[i]=parent->child[i+1];
                    }
                    for (int i = parentKeyPos + 1; i < parent->numKeys; i++)
                    {
                        parent->child[i] = parent->child[i + 1];
                    }
                    parent->numKeys--;
                    free(leftSibling);
                    leftChildPointer = NULL;
                }
                else
                {
                    // copying rightchild keys into nodeToDelete keys.
                    int j = 0;
                    for (int i = nodeToDelete->numKeys; i < m; i++)
                    {
                        nodeToDelete->key[i] = rightSibling->key[j];
                        j++;
                    }
                    sort(nodeToDelete->key, nodeToDelete->key + m);
                    nodeToDelete->numKeys += rightSibling->numKeys;
                    // replace the keyToDelete with the parents key
                    int i;
                    for (i = 0; i < parent->numKeys; i++)
                    {
                        if (parent->key[i] > key)
                        {
                            break;
                        }
                    }
                    int parentKeyPos = i;
                    for (int i = 0; i < nodeToDelete->numKeys; i++)
                    {
                        if (nodeToDelete->key[i] == key)
                        {
                            nodeToDelete->key[i] = parent->key[parentKeyPos];
                            break;
                        }
                    }
                    // shifting due to the deleted key in the parent node
                    for (int i = parentKeyPos; i < parent->numKeys - 1; i++)
                    {
                        parent->key[i] = parent->key[i + 1];
                        // parent->child[i] = parent->child[i + 1];
                    }
                    for (int i = parentKeyPos + 1; i < parent->numKeys; i++)
                    {
                        parent->child[i] = parent->child[i + 1];
                    }
                    parent->numKeys--;
                    free(rightSibling);
                    rightChildPointer = NULL;
                }
                //fixup the parent
                delete_key(parent, key);
        }
    }
}}

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