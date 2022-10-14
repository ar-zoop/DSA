#include <bits/stdc++.h>
using  namespace std;

int main(){
    int a[5]={1,1,1,1,1}, b[5]={1,0,0,0,0};
    array<int,6> c;
    int cy=0;
    for(int i=4; i>=0; i--){
        if(a[i]==1 && b[i]==1){
            if(cy==1){
                c[i+1]=1;
            }
            else{
                c[i+1]=0;
            }
        }
        else if((a[i]==1 && b[i]==0)|| (b[i]==1 && a[i]==0)){
            if(cy==1){
                c[i+1]=0;
            }
            else{
                c[i+1]=1;
            }
        }
        else{
            if(cy==1){
                c[i+1]=1;
            }
            else{
                c[i+1]=0;
            }
        }
        if(cy==1 && ((a[i]==1 && b[i]==0)||(a[i]==0)&&b[i]==1 )){
            cy=1;
        }
        else if(a[i]==1 && b[i]==1){
            cy=1;
        }
        else{
            cy=0;
        }
       
    }
    if(cy==1){
        c[0]=1;
    }
    else{
        c[0]=0;
    }
    for(int i=0;i<c.size();i++){
        cout<<c[i]<<" ";
    }
    return 0;
}