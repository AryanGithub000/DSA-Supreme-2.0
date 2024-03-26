/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution
{
    public: 
    void solve(Node* root,Node* &temp){ //temp is head here
        //base case
    if(root==NULL) return;
    
    //1 case i solve
    //RNL
    //R
    solve(root->right,temp);
    
    //N
    //1. connect root->right =head
    root->right=temp;
    //2. connect Right wala to head
    if(temp!=NULL) temp->left=root;
    //3. head ko root par le aao
    temp=root;
    
    
    //L
    solve(root->left,temp);
        
    //return temp;
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root){
        Node* temp=NULL;
        solve(root,temp);
        return temp;
    }
};
