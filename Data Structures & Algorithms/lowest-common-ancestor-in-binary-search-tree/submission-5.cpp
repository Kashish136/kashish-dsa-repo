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

    // bool search(TreeNode*root  , TreeNode*node){
         
    //      if(!root){
    //         return false ;
    //      }

    //     if(root->val > node->val){
    //         return search(root->left , node);
    //     }

    //     if(root-> val < node->val){
    //        return search(root->right , node);
    //     }
       
    //     return true  ;
    // }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
           
        //    if(!root || !p || !q){
        //     return NULL;
        //    }

        //    if(root == p || root == q){
        //     return root ;
        //    }


           
        // TreeNode* left = lowestCommonAncestor(root->left, p, q);
        // TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // // found in both sides
        // if(left && right) {
        //     return root;
        // }

        // // found only on one side
        // if(left) {
        //     return left;
        // }

        // return right;
       
        if(root->val == p->val || root->val == q->val){
            return root;
        }

        if(!root){
            return nullptr;
        }


        if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->left , p , q)
        }

        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->right , p ,q);
        }

        return root ;
    } 
};
