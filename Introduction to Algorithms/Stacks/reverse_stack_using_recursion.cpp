#include <bits/stdc++.h>
using  namespace std;

//building a stack

#define SIZE 3
int st[SIZE];
int top=-1;
int top2=-1;
int st2[SIZE];
bool isempty(){
    if(top==-1) return true;
    return false;
}

bool isfull(){
    if(top==SIZE-1) return true;
    return false;
}

void push(int stackNo, int data){
    if(stackNo==1)
    {    if(!isfull()){
            st[++top]=data;
        }
        else{
            cout<<"Overflow"<<endl;
        }
    }
    else{
        st2[++top2]=data;
    }
}
int peek(int stackNo){
    if (stackNo==1){
    if(!isempty()){
        return st[top];
    }}
   
    if(!isempty()){
        return st2[top2];    
    }
    return -1;
}
void pop(int stackNo){
    if(stackNo==1){
        if(!isempty()){
            cout<<st[top--]<<" was popped."<<endl;
        }
        else{
            cout<<"Underflow"<<endl;
        }
    }
    else{
        if(!isempty()){
            top2--;
        }
        else{
            cout<<"Underflow"<<endl;
        }
    }
}

void display(){
    int temp=top2;
    while(top2!=-1){
        peek(2);
        pop(2);
    }
    top2=temp;
}
// reverse a stack
void reverse(int top){
    if(top==-1) return;
    int data=peek(2);
    pop(1);
    push(2, data);
    reverse(top--);
}

int main(){
    push(1, 5);
    push(1, 4);
    push(1, 3);
    push(1, 2);
    reverse(top2);
// display(1);
    display();
    return 0;
} 