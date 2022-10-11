//1. create heap
//2. delete node
//3. max heapify

#include <bits/stdc++.h>
using namespace std;

/*
int s=0;
int heap[9]={1,2,3,4,5,6,7,8,9};

void max_heapify(int i){
    int left=((i+1)*2);
    int right=(i+1)*2+1;
    int largest=i;
    if(left<=s && heap[left]>heap[i]){        
        largest=left;        
    }
    if(right<=s && heap[right]>heap[largest]){        
        largest=right;        
    }
    if(largest!= i){
        swap(heap[i],heap[largest]);
        max_heapify(largest);
    }
    return;
}

void parent_heapify(int i){
    // i++;
    int parent=(i+1)/2 -1;
    if(parent>=0 && (i)<s && heap[parent]<heap[i]){
        swap(heap[parent], heap[i]);
        parent_heapify(parent);
    }
    return;
}


void delete_heap(){    
    swap(heap[0],heap[--s]);
    for(int i=(s/2);i>=0;i--){
        max_heapify(i);
    }
    
}

int main(){
    
     for(int i=(9/2);i>=0;i--){
        max_heapify(i);
    }
     for(int i=0;i<9;i++){
        delete_heap();
    }
     for(int i=0;i<9;i++){
        cout<<heap[i]<<" ";
    }
   
    return 0;
}
*/

int s=9;
int heap[9]={1,2,3,4,5,6,7,8,9};

void heapify(int i){
    int parent=((i+1)/2) -1 ;
    if(parent>=0 && heap[i]>heap[parent]){
        swap(heap[i],heap[parent]);
        heapify(parent);
    }
    return ;
}

void create_heap(){
    for(int i=0;i<9;i++){
        heapify(i);
    }
}
void max_heapify(int i){
    int left=((i+1)*2)-1;
    int right=(i+1)*2;
    int largest=i;
    if(left<=s && heap[left]>heap[i]){        
        largest=left;        
    }
    if(right<=s && heap[right]>heap[largest]){        
        largest=right;        
    }
    if(largest!= i){
        swap(heap[i],heap[largest]);
        max_heapify(largest);
    }
    return;
}

void delete_heap(){
    swap(heap[0],heap[--s]);
    max_heapify(0);
}

int main(){
    create_heap();
    for(int i=0;i<9;i++)
        delete_heap();
    for(int i=0;i<9;i++){
        cout<<heap[i]<<" ";
    }
}