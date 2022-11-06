#include <bits/stdc++.h>
using  namespace std;

void inorder_traversal(vector<int> &arr){
    stack<int>stk;
    int i=0;
    do{
        while(i<arr.size()){
            stk.push(i);
            i=(2*(i+1))-1;
        }
        int pos=stk.top();
        cout<<arr[pos]<<endl;
        stk.pop();
        if(!stk.empty()){
            pos=stk.top();
            cout<<arr[pos]<<endl;
            stk.pop();
            
        }
        i = ((pos + 1) * 2);
    } while (!stk.empty() || i==2);
    return;
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8,9,10};
    inorder_traversal(arr);
    return 0;
} 