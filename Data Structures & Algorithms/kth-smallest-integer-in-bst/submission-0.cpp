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

    void helper(TreeNode*root , vector<int>&temp){


        if(!root){
            return;
        }

        if(temp[0] == 0){
            return ;
        }

        helper(root->left , temp);
        if(temp[0] == 0){
            return ;
        }

        temp[0]--;
        if(temp[0] == 0){
            temp[1] = root->val;
            return ;
        }

        dfs(root->right, temp);
    }
    int kthSmallest(TreeNode* root, int k) {
         

        vector<int>temp(2,0);
        temp[0] = k;

        helper(root , temp)
        return temp[1];
        

    }
};