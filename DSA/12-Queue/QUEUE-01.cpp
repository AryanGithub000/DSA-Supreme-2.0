/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <deque>
using namespace std;

// class Queue{
//     public:
//     int *arr;
//     int size;
//     int front;
//     int rear;
    
//     Queue(int size){
//         arr= new int[size];
//         this->size=size;
//         front=-1;
//         rear=-1;
//     }
    
//     void push(int val){
//         //check full
//         if(rear==size-1){
//             cout<<"Overflow!"<<endl;
//         }
//         else if(front==-1 && rear==-1){
//             //empty queue
//             rear++;
//             front++;
//             arr[rear]=val;
//         }
//         else{
//             //normal case
//             rear++;
//             arr[rear]=val;
//         }
//     }
    
//     void pop(){
//         //empty
//         if(front==-1 && rear==-1){
//             cout<<"Underflow!"<<endl;
//         }
//         //single elt.
//         else if(front==rear){
//             arr[front]=-1; //to remove it mark as -1 in arr
//             front=-1;
//             rear=-1;
//         }
//         //normal case
//         else{
//             arr[front]=-1;
//             front++;
//         }
//     }
    
//     bool isEmpty(){
//         if(front==-1 && rear==-1) return true;
//         else return false;
//     }
    
//     int getSize(){
//         //empty case
//         if(front==-1 && rear==-1){
//             return 0;
//         }
//         //normal case
//         else{
//         return rear-front+1;
//         }
//     }
    
//     int getFront(){
//         if(front==-1){ //empty
//             cout<<"No elt. in queue can give front elt."<<endl;
//             return -1;
//         }
//         else{
//             return arr[front];
//         }
//     }
    
//     int getRear(){
//         if(rear == -1){ // empty
//             cout << "No element in queue." << endl;
//             return -1;
//         }
//         else{
//             return arr[rear];
//         }
//     }
    
//     void print(){
//         cout<<"Printing Queue: ";
//         for(int i=0;i<size;i++){
//             cout<<arr[i]<<" ";
//         }
//         cout<<endl;
//     }
// };

// class Cqueue{ //circular queue
//     public:
//     int *arr;
//     int size;
//     int front;
//     int rear;
    
//     Cqueue(int size){
//         arr= new int[size];
//         this->size=size;
//         front=-1;
//         rear=-1;
//     }
    
//     void push(int val){  
//         //check full
//         if(front==0 && rear==size-1 || (rear==front-1)){
//             cout<<"Overflow!"<<endl;
//         }
//         else if(front==-1 && rear==-1){
//             //empty queue
//             rear++;
//             front++;
//             arr[rear]=val;
//         }
//         else if(rear==size-1 && front!=0){
//             //circular nature
//             rear=0;
//             arr[rear]=val;
//         }
//         else{
//             //normal case
//             rear++;
//             arr[rear]=val;
//         }
//     }
    
//     void pop(){
//         //empty
//         if(front==-1 && rear==-1){
//             cout<<"Underflow!"<<endl;
//         }
//         //single elt.
//         else if(front==rear){
//             arr[front]=-1; //to remove it mark as -1 in arr
//             front=-1;
//             rear=-1;
//         }
//         //circular nature
//         else if(front==size-1){
//             arr[front]=-1;
//             front=0;
//         }
//         //normal case
//         else{
//             arr[front]=-1;
//             front++;
//         }
//     }
   
//     void print(){
//         cout<<"Printing Queue: ";
//         for(int i=0;i<size;i++){
//             cout<<arr[i]<<" ";
//         }
//         cout<<endl;
//     }
// };


int main(){
//     //create 
//     Queue q(5); ****************************************************************************************************
//     //q.print();
    
//     q.push(10);
//     q.push(20);
//     q.push(30);
//     q.push(40);
//   // q.print();
    
//     cout<<"Size of queue: "<<q.getSize()<<endl;
    
//     q.pop();
//   // q.print();
    
//     cout<<"Size of queue: "<<q.getSize()<<endl;
    
//     cout<<"Queue is empty or not? "<<q.isEmpty()<<endl;
    
//     q.push(100);
//     q.push(200);
//     cout<<q.getRear();
    
//     q.pop();
//     q.pop();
//     q.pop();
//     q.pop();
//   // q.print();
    
//     q.push(300);


    // Cqueue q(5); ****************************************************************************************************
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    
    // q.pop();
    // q.pop();
    // q.pop();
    
    
    // q.push(60); //inserted at 0th index 
    // q.push(70);
    // q.push(80);
    
    // q.push(90); //overflow corrected as (rear==front-1) par hoga
    // q.print();
    
    
    //DEQUE ****************************************************************************************************
    // deque<int> dq;
    
    // dq.push_back(10);
    // dq.push_front(100);
    
    // dq.pop_back();
    
    // cout<<dq.front()<<endl;
    // cout<<dq.back()<<endl;
    
    // cout<<dq.size()<<endl;
    
    
    return 0;
}


