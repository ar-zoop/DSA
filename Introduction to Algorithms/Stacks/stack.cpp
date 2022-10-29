#include <bits/stdc++.h>
using  namespace std;
#define SIZE 3
int st[SIZE];
int top=-1;

bool isempty(){
    if(top==-1) return true;
    return false;
}

bool isfull(){
    if(top==SIZE-1) return true;
    return false;
}

void push(int data){
    if(!isfull()){
        st[++top]=data;
    }
    else{
        cout<<"Overflow"<<endl;
    }

}

void pop(){
    if(!isempty()){
        cout<<st[top--]<<" was popped."<<endl;
    }
    else{
        cout<<"Underflow"<<endl;
    }
}
int main(){
    push(5);
    push(4);
    push(3);
    push(2);
    pop();
    pop();
    pop();
    return 0;
} 