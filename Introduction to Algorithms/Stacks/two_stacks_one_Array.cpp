#include <bits/stdc++.h>
using  namespace std;
#define SIZE 10
int top1=-1, top2=SIZE;
int arr[SIZE];

bool is_full(){
    if((top1+1)==top2){
        return true;
    }
    else return false;
}

void push1(int data){
     if(!is_full()){
        arr[++top1]=data;
    }
    else{
        cout<<"Overflow"<<endl;
    }
}

void push2(int data){
    if(!is_full()){
        arr[--top2]=data;
    }
    else{
        cout<<"Overflow"<<endl;
    }
}

void pop1(){
    if(top1!=-1){
        cout<<"Popped element "<<arr[top1--]<<endl;
    }
    else{
        cout<<"Underflow"<<endl;
    }
}

void pop2(){
    if(top2!=SIZE){
        cout<<"Popped element "<<arr[top2++]<<endl;
    }
    else{
        cout<<"Underflow"<<endl;
    }
}


int main(){

    push1(5);
    push1(5);
    push1(5);
    push2(1);
    push2(1);
    push2(1);
    push1(5);
    push1(5);
    push1(5);
    push2(1);
    push1(5);
    pop1();
    pop2();
    pop1();
    pop2();
    pop1();
    pop2();
    pop1();
    pop2();
    pop1();
    pop2();
    pop1();
    pop2();
    return 0;
} 