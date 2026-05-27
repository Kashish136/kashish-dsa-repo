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

    unordered_map<TreeNode*, int>mpp;

    int helper(TreeNode*root){

       if(mpp.find(root) != mpp.end()){
        return mpp[root];
       }


         int pick = root->val;

        if (root->left) {
            pick += rob(root->left->left);
            pick += rob(root->left->right);
        }

        if (root->right) {
            pick += rob(root->right->left);
            pick += rob(root->right->right);
        }

        // don't pick current node
        int not_pick = rob(root->left) + rob(root->right);

        return mpp[root] = max(pick, not_pick);

        
    }
    int rob(TreeNode* root) {

        // if (!root) return 0;

        // // pick current node
        // int pick = root->val;

        // if (root->left) {
        //     pick += rob(root->left->left);
        //     pick += rob(root->left->right);
        // }

        // if (root->right) {
        //     pick += rob(root->right->left);
        //     pick += rob(root->right->right);
        // }

        // // don't pick current node
        // int not_pick = rob(root->left) + rob(root->right);

        // return max(pick, not_pick);
        mpp[nullptr] = 0;
        return helper(root);
        
    }
};