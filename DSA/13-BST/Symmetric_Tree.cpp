/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    bool solve(Node* left,Node* right){
        if(left==NULL && right==NULL) return true;
        if (left == NULL || right == NULL) return false;
        if (left->data != right->data) return false;
        
        return solve(left->left,right->right) && solve(left->right,right->left);
        
    }
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root){
	    if(root==NULL) return true; //empty tree
	    
	    return solve(root->left, root->right);
	    
    }
};
