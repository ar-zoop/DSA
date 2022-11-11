#include <bits/stdc++.h>
#include <chrono>
using  namespace std;
using namespace std::chrono;

void push(queue<int> &q_main, int data){
    q_main.push(data);
}

void pop(queue<int> &q_main){
    queue<int> q_aux;
    if(q_main.empty()){
        cout<<"underflow";
        return;
    }
    while(q_main.size()>1){
        q_aux.push(q_main.front());
        q_main.pop();
    }
    // cout<<"Item deleted: "<<q_main.front()<<endl;
    q_main.pop();
    swap(q_main, q_aux);
}

void peek(queue<int> &q)
{
    if (q.empty())
        return;
    cout<<q.back()<<endl;
    return;
}

int main()
{
    // instantiation of std::chrono::duration:- 1 second
    // milliseconds mil(1000);
    auto start = high_resolution_clock::now();
    queue<int> q_main;
    push(q_main,1);
    push(q_main, 2);
    push(q_main, 3);
    push(q_main, 4);
    push(q_main, 5);
    peek(q_main);
    pop(q_main);
    peek(q_main);
    pop(q_main);
    peek(q_main);
    pop(q_main);
    peek(q_main);
    pop(q_main);
    peek(q_main);
    pop(q_main);
    peek(q_main);
    pop(q_main);
    peek(q_main);
    // std::cout << "duration (in periods): ";
    // std::cout << setprecision(9) << (double)mil.count() << " milliseconds.\n";
    
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\ntime taken - ";
    double d = duration.count()/1000000.0;
    cout << std::setprecision(9)<< d<< endl;
    return 0;
}
