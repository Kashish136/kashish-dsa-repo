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

   TreeNode*helper(TreeNode*root , int key){

      TreeNode*current = root;
    while(root->left != nullptr){
        root = root->left;
    }

     return root ;
   }

   // my secret for finding out the smallest value in the right subtree
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        
    if(!root){
        return nullptr;
    }

    if(root->val > key){
        return deleteNode(root->left , key);
    }

    else if(root->val < key){
        return deleteNode(root->right , key);
    }


    else{

    



        if(!root->left && !root->right && root->val == key){
            delete root;
            return nullptr ;
        }
        else if(root->left != nullptr){
            TreeNode*temp = root->left;
            delete root;
            return temp;
        }

        else if(root->right != nullptr){
            TreeNode*temp = root->right;
            delete root ;
            return temp ;
        }

        else{

            TreeNode*newnode = helper(root->right , key);
            root->val = newnode->val;
            root->right = deleteNode(root->right , key);

        }

    }
    }
};