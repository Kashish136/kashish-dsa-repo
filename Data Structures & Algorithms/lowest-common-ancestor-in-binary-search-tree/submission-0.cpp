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

    bool search(TreeNode*root  , TreeNode*node){
         
         if(!root){
            return false ;
         }

        if(root->val > node->val){
            return search(root->left , node);
        }

        if(root-> val < node->val){
           return search(root->right , node);
        }
       
        return true  ;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        bool left1 = search(root->left , p)
        bool left2 = search(root->left , q);

        bool right1 = search(root->right , p);
        bool right2 = search(root->right , q);

        if(left1&&left2){
            return lowestCommonAncestor(root->left , p ,q);
        }

        if(right1 && right2){
            return lowestCommonAncestor(root->right , p , q);
        }


        return root ;

    } 
};
