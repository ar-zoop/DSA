#include <bits/stdc++.h>
using  namespace std;
void rev(stack<int>stk){
    if(stk.empty()) return;
    else{
        int top=stk.top();
        stk.pop();
        rev(stk);
        stk.push(top);
    }
}
int main(){
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    rev(stk);
    while(!stk.empty()){
        cout<<stk.top();
        stk.pop();
    }
    return 0;
} 