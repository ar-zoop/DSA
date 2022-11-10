#include <bits/stdc++.h>
#define MAX 4
using  namespace std;

int front=-1, rear=-1;

void enqueue(vector<int>& circle, int data){
    if((rear+1)%MAX==front) cout<<"Overflow";
    else if(front==-1){
        circle[++front]=data;
        rear++;
    }
    else if(rear==circle.size()-1){
        rear = 0;
        circle[rear] = data;
        
    }
    else{
        circle[++rear] = data;
    }
}

void dequeue(vector<int> &circle)
{
    //check for underflow
    if(front==-1){
        cout<<"underflow"<<endl;
    }
    else if(front==rear){
        cout << "item dequeued " << circle[front]<<endl;
        front=-1, rear=-1;
    }
    else{
        cout<<"item dequeued "<<circle[front]<<endl;
        front++;
        if(front==MAX){
            front=0;
        }
    }
}

    int main()
{
    vector<int> circle(MAX);
    enqueue(circle,10);
    enqueue(circle,20);
    enqueue(circle,30);
    enqueue(circle,40);
    dequeue(circle);
    enqueue(circle,50);
    dequeue(circle);
    dequeue(circle);
    dequeue(circle);
    dequeue(circle);
    enqueue(circle, 60);
    enqueue(circle, 70);
    enqueue(circle, 80);
    enqueue(circle, 90);
    dequeue(circle);
    enqueue(circle, 100);
    dequeue(circle);
    dequeue(circle);
    dequeue(circle);
    dequeue(circle);
    dequeue(circle);

    return 0;
}