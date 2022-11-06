#include <bits/stdc++.h>
using  namespace std;

void insert_sorted(int ele, stack<int> &stk){
    if (stk.empty() || ele >= stk.top())
    {
        stk.push(ele);
        return;
    }
    else{
        int top=stk.top();
        stk.pop();
        insert_sorted(ele,stk);
        stk.push(top);
    }
}

void sort_stack(stack<int> &stk){
    if(stk.empty()) return;
    int top=stk.top();
    stk.pop();
    sort_stack(stk);
    insert_sorted(top, stk);
    return;
}

int main(){
    stack<int> stk;
    stk.push(9);
    stk.push(-1);
    stk.push(120);
    stk.push(2);
    sort_stack(stk);
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
} 