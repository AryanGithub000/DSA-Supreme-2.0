#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q){ //by reference as to change existing queue
    stack<int> st;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        
        st.push(front);
    }
    
    //now push into queue
    while(!st.empty()){
        int element=st.top();
        st.pop();
        
        q.push(element);
    }
}

void reverse(queue<int> &q){
    //BC
    if(q.empty()) return;
    
    int element=q.front();
    q.pop();
    
    //recursion
    reverse(q);
    
    q.push(element);
}

int main(){
    
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    
    //reverseQueue(q); //reverse the queue
    //reverse(q);
    cout<<"Printing Queue: "<<endl;
    while(!q.empty()){
        int element=q.front();
        q.pop();
        cout<<element<<" ";
    }
    return 0;
}
