/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int value){
        this->data=value;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* insertIntoBST(Node* root,int data){
    if(root==NULL){
        //create first Node
        root=new Node(data); 
        return root;
    }
    
    //its not the first node 
    if(data > root->data){
        //right jao
        root->right=insertIntoBST(root->right,data);
    }
    else{
        //left jao
        root->left=insertIntoBST(root->left,data);
    }
    return root;
}

void createBST(Node* &root){
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    
    while(data!=-1){
        root=insertIntoBST(root,data); //data process karo as BST
        cin>>data; //for next nodes
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root); 
    q.push(NULL);
    
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
    }
}

int main()
{
    Node* root= NULL;
    createBST(root); //data input lelo 
    
    levelOrderTraversal(root);
    
    //50 30 20 25 40 60 70 80 55 -1 input eg 
    
    //output
    //50 
    //30 60 
    //20 40 55 70
    //25 80
    

    return 0;
}
