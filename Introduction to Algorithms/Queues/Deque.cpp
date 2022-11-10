#include <bits/stdc++.h>
#define MAX 5
using namespace std;

int front=-1, rear=-1;

void fenqueue(vector<int> &deque, int data)
{
    if(front==-1){
        deque[++front]=data;
        rear++;
    }
    else if(front>0){
        deque[--front]=data;
    }
    else{
        cout<<"No space"<<endl;
    }
}

void renqueue(vector<int> &deque, int data)
{
    if(rear==-1){
        deque[++rear]=data;
        front++;
    }
    else if(rear==MAX-1){
        cout<<"Overflow"<<endl;
    }
    else{
        deque[++rear]=data;
    }
}

void rdequeue(vector<int> &deque)
{
    if(rear==-1){
        cout<<"Underflow"<<endl;
    }
    else if (front == rear)
    {
        cout << "Element deleted is: " << deque[rear]<<endl;
        front = -1, rear = -1;
    }
    else{
        cout << "Element deleted is: " << deque[rear--]<<endl;
        
    }
}
void fdequeue(vector<int> &deque)
{
    if(front==-1) cout<<"Underflow"<<endl;
    else if (front == rear)
    {
        cout << "Element deleted is: " << deque[rear]<<endl;
        front = -1, rear = -1;
    }
    else
    {
        cout << "Element deleted is: " << deque[front++]<<endl;
    }
    
}

int main(){
    vector <int> deque(MAX);
    fenqueue(deque, 1);
    fenqueue(deque, 1);
    renqueue(deque, 2);
    renqueue(deque, 3);
    renqueue(deque, 4);
    renqueue(deque, 5);
    fdequeue(deque);
    fdequeue(deque);
    fenqueue(deque,2);
    fenqueue(deque,1);
    rdequeue(deque);
    rdequeue(deque);
    rdequeue(deque);
    rdequeue(deque);
    rdequeue(deque);
    rdequeue(deque);

    return 0;
} 