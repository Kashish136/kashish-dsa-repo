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

  int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(!root){
            return 0 ;
        }

        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);


        diameter = max(diameter , (right+left));

        return 1+max(left , right);
    }
};
