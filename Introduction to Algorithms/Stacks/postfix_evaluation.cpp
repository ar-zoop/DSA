#include <bits/stdc++.h>
using  namespace std;

int postfix_eval(){
    stack<int> stk;
    string exp = "231*+9-";
    int n=exp.length();
    for(int i=0; i<n; i++){
        if(isdigit(exp[i])){
            string s="";
            s+=exp[i];
            stk.push(stoi(s));
            // cout<<stoi(s)<<endl;
        }
        else{
            // cout << "hello";
            int num1=stk.top();
            stk.pop();
            int num2= stk.top();
            stk.pop();
            if(exp[i]=='+'){
                stk.push(num1+num2);
            }
            else if(exp[i]=='-'){
                stk.push(num2-num1);
            }
            else if(exp[i]=='*'){
                stk.push(num1*num2);
            }
            else if(exp[i]=='/'){
                stk.push(num2/num1);
            }
        }
    }
    
    return stk.top();
}

int main(){
    int ans = postfix_eval();
    cout << ans;
    return 0;
} 