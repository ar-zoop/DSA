#include <bits/stdc++.h>
using  namespace std;

bool check_duplicates(){
    stack<char> stk;
    string a = "(((a+b)+(c*d)))";
    int a_len = a.length();
    for (int i = 0; i < a_len; i++)
    {
        if(a[i]==')')
        {
            if (stk.top() == '(')
                return true;
            while (!stk.empty() && stk.top() != '(')
            {
                stk.pop();
            }
            stk.pop();
        }  
        else{
            stk.push(a[i]);
        }      
    }
    return false;
}

int main(){
    bool ans=check_duplicates();
    cout<<ans;
    return 0;
} 