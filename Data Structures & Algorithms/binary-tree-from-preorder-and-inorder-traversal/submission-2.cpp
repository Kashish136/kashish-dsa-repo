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

    TreeNode*helper( vector<int>&preorder , vector<int>&inorder , int prestart , int preend , int instart , int inend ,map<int,int>mpp){



          if(prestart > preend || instart > inend){
            return nullptr ;
          }

          TreeNode*root = new TreeNode(preorder[prestart]);
          int index = mpp[preorder[prestart]];
          int numsleft =  index-instart;

          root->left = helper(preorder , inorder , prestart + 1 , prestart + numsleft , instart, instart+index-1 , mpp );

          root->right = helper(preorder , inorder , prestart + numsleft+1 , preend , inroot+1 , inend , mpp);


          return root ;

       }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        

        map<int,int>mpp;
        for( int i = 0 ; i < inorder.size() ; i++){
            mpp[inorder[i]] = i;
        }

        return helper(preorder , inorder , 0 , preorder.size()-1 , 0 , inorder.size()-1 , mpp);
    };

