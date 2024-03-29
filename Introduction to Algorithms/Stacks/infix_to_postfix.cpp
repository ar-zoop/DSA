
#include <bits/stdc++.h>
using namespace std;

int precedence(char& c){
    switch(c){
        case '+': return 1; break;
        case '-': return 1; break;
        case '*': return 2; break;
        case '/': return 2; break;
        case '%': return 2; break;
        case '^': return 3; break;
        default : return 0; break;
    }
}

string postfixConverter(string& s){
    string ans;
    stack<char> st;
    s='('+s+')';
    // cout<<s<<endl;
    for(char& c: s){
        // cout << c<< " ";
        if(isalnum(c)) ans+=c;
        else if(c=='(') st.push('(');
        else if(c==')'){
            while(st.top()!='('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else if ((!st.empty() && precedence(c) <= precedence(st.top())))
        {
            while(!st.empty() && precedence(c) <= precedence(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(c);
        }
        else{
            st.push(c);
        }
    }
    while(!st.empty()) ans+=st.top(); st.pop();
    // cout << "asd" << ans;
    return ans;
}

int main(){
    string s= "1*5+7";
    s= postfixConverter(s);
    cout<<s<<endl;
    return 0;
}
