#include <bits/stdc++.h>
using  namespace std;
int main(){
    stack<char> stk;
    string word="arzoo";
    for(int i=0; i<word.length(); i++){
        stk.push(word[i]);
    }
    while(!stk.empty()){
        cout<<stk.top();
        stk.pop();
    }
    
    return 0;
} 