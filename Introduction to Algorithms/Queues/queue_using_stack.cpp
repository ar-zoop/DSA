// Enqueue expensice
#include <bits/stdc++.h>
using  namespace std;

void enqueue(stack<int> &st1, stack<int>&st2, int data){
    while(!st2.empty()){
        st1.push(st2.top());
        st2.pop();
    }
    st1.push(data);
    while(!st1.empty()){
        st2.push(st1.top());
        st1.pop();
    }
}

void dequeue(stack<int> &st2)
{
    if(st2.empty()) cout<<"underflow";
    else{
        cout<<"Element delete is : "<<st2.top()<<endl;
        st2.pop();
    }
}

int main(){
    stack<int> st1;
    stack<int> st2;
    enqueue(st1, st2, 10);
    enqueue(st1, st2, 20);
    enqueue(st1, st2, 30);
    enqueue(st1, st2, 40);
    while(!st1.empty()){
        cout<<st1.top()<<" ";
        st1.pop();
    }
    dequeue(st2);
    dequeue(st2);
    dequeue(st2);
    dequeue(st2);
    return 0;
} 