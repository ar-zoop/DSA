#include <bits/stdc++.h>
using  namespace std;

bool check_balanced(){
    stack<char> stk;
    string arr = "{[]}()()";
    for (int i = 0; i < arr.length(); i++)
    {
        if (arr[i] == '{' || arr[i] == '[' || arr[i] == '(')
        {
            stk.push(arr[i]);
        }
        else if (arr[i] == '}' || arr[i] == ']' || arr[i] == ')')
        {
            char bracket;
            if (arr[i] == '}')
                bracket = '{';
            else if (arr[i] == ']')
                bracket = '[';
            else
                bracket = '(';
            while (!stk.empty() && stk.top() != bracket)
            {
                stk.pop();
            }
            if (!stk.empty() && stk.top() == bracket)
            {
                stk.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if(!stk.empty()) return false;
    return true;
}

int main(){
    cout<<check_balanced();
    return 0;
} 