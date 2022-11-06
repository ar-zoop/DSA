#include <bits/stdc++.h>
using  namespace std;


void prefix_to_postfix(){
    stack<string>stk;
    string exp ="*-A/BC-/AKL";

    int n=exp.length();
    for(int i=n-1; i>=0; i--){
        string ans = "";
        if(isalpha(exp[i])){
            // string str="";
            ans+=exp[i];
            stk.push(ans);
        }
        else {           
            if(!stk.empty()){                
                ans+=stk.top(); stk.pop();
                ans+=stk.top(); stk.pop();
            }
            ans+=exp[i];   
            stk.push(ans);
        }
       
    }
    while(!stk.empty()){
        cout<<stk.top();
        stk.pop();
    }
}

int main(){
    prefix_to_postfix();
    return 0;
} 