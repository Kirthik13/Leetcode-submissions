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
    // int sum=0;
    int fn(TreeNode* &root,int prev)
    {
        if(!root)
        {
            return prev;
        }
        
        int rsum=fn(root->right,prev);
        
        root->val+=rsum;
        int lsum=fn(root->left,root->val);
        return lsum;
    }
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
        {
            return NULL;
        }
        
        int g=fn(root,0);
        return root;
        
    }
};