#include <bits/stdc++.h>
#define MAX 5
using namespace std;

int f=-1, r=-1;

void fenqueue(vector<int> &deque, int data)
{
    if(f==-1){
        deque[++f]=data;
        r++;
    }
    else if(f>0){
        deque[--f]=data;
    }
    else{
        cout<<"No space"<<endl;
    }
}

void renqueue(vector<int> &deque, int data)
{
    if(r==-1){
        deque[++r]=data;
        f++;
    }
    else if(r==MAX-1){
        cout<<"Overflow"<<endl;
    }
    else{
        deque[++r]=data;
    }
}

void rdequeue(vector<int> &deque)
{
    if(r==-1){
        cout<<"Underflow"<<endl;
    }
    else if (f == r)
    {
        cout << "Element deleted is: " << deque[r]<<endl;
        f = -1, r = -1;
    }
    else{
        cout << "Element deleted is: " << deque[r--]<<endl;
        
    }
}
void fdequeue(vector<int> &deque)
{
    if(f==-1) cout<<"Underflow"<<endl;
    else if (f == r)
    {
        cout << "Element deleted is: " << deque[r]<<endl;
        f = -1, r = -1;
    }
    else
    {
        cout << "Element deleted is: " << deque[f++]<<endl;
    }
    
}

int main(){
    vector <int> deque(MAX);
    fenqueue(deque, 1);
    fenqueue(deque, 1);
    renqueue(deque, 2);
    renqueue(deque, 3);
    renqueue(deque, 4);
    renqueue(deque, 5);
    fdequeue(deque);
    fdequeue(deque);
    fenqueue(deque,2);
    fenqueue(deque,1);
    rdequeue(deque);
    rdequeue(deque);
    rdequeue(deque);
    rdequeue(deque);
    rdequeue(deque);
    rdequeue(deque);

    return 0;
} 