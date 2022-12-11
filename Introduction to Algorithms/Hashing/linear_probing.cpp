#include <bits/stdc++.h>
using namespace std;
int main(){
    int i=0;
    int hashtable [10]={0};
    int key=4;
    int value=400;
    hashtable[6]=6;
    while(true && j<10){
        int j=6+i;//made from a key value formula involving k and i
        if(hashtable[j]==0) {
            hashtable[j]=value; 
            break;
        }
        else{
            i++;
        }
    }
    for(int i=0; i<10; i++){
        cout<<hashtable[i]<<" ";
    }
    return 0;
}