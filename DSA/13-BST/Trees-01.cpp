/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int val){
            this->data=val;
            this->left=NULL;
            this->right=NULL;
        }
        
        
};

//returns root node of the created tree
Node* createTree(){
    cout<<"enter the value for Node: "<<endl;
    int data;
    cin>>data;
    
    if(data==-1) return NULL; //base case also 
    
    //step1: node banao ab 
    Node* root=new Node(data);  
    
    //step2: create left subtree
    cout<<"enter the value for left Node: "<<endl;
    root->left=createTree();
    
    //step3: create right subtree
    cout<<"enter the value for right Node: "<<endl;
    root->right=createTree();
    
    return root;
}

void preOrderTraversal(Node* root){
    //bc 
    if(root==NULL){
        return;
    }
    //N L R --> pre order traversal
    //N 
    cout<<root->data<<" ";
    //L 
    preOrderTraversal(root->left);
    //R 
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    //bc 
    if(root==NULL){
        return;
    }
    //L N R --> in order traversal
    //L 
    inOrderTraversal(root->left);
    //N 
    cout<<root->data<<" ";
    //R 
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    //bc 
    if(root==NULL){
        return;
    }
    //L R N--> post order traversal
    //L 
    postOrderTraversal(root->left);
    //R 
    postOrderTraversal(root->right);
    //N 
    cout<<root->data<<" ";
}

int main(){
    Node* root=createTree(); 
   // cout<<root->data<<endl;
    
    //post order
    postOrderTraversal(root);
    return 0;
}
