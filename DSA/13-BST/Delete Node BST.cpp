/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxValue(TreeNode* root){
        TreeNode* temp=root;
        if(temp==NULL) return -1;

        while(temp->right!=NULL){
            temp=temp->right;
        }
        return temp->val;
    }

    TreeNode* deleteNode(TreeNode* root, int target) {
        if(root==NULL){
            return NULL;
        }

        if(root->val==target){
            //4 cases
            //1.leaf node
            if(root->left==NULL && root->right==NULL){
                //delete root;
                return NULL;
            }

            //2. one side null and other not
            if(root->left!=NULL && root->right==NULL){
                TreeNode* temp=root->left; //as left mei value hai
                //delete root;
                return temp;
            }

            //3. same as 2
            if(root->left==NULL && root->right!=NULL){
                TreeNode* temp=root->right; //as right mei value hai
                //delete root;
                return temp;
            }

            //4. check for max in left sub tree to replace as root
            else{
                int maxi=maxValue(root->left); //get max value in left sub tree
                root->val=maxi; //data replace karo in root
                root->left = deleteNode(root->left,maxi); //delete the node
                return root;
            }
        }

        //not found target
        //traverse each sides
        else if(root->val< target){
            root->right = deleteNode(root->right,target);
        }
        else{
            root->left = deleteNode(root->left,target);
        }
        return root;
    }
};
