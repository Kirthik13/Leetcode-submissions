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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    { 
        if(!root) return {};
        if(!root->left and !root->right) return {{root->val}};
        vector<vector<int>>tot;
        queue<TreeNode*>q;
        q.push(root);
        int f=0;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>sam(n);
            for(int i=0;i<n;i++){
                TreeNode* t=q.front();

                q.pop();
                // int idx;
                int idx=(f==1)?n-1-i:i;
                sam[idx]=t->val;
                
                    if(t->left)
                    {
                        q.push(t->left);
                    }
                    if(t->right)
                    {
                        q.push(t->right);
                    }
                   
                
            }
           f=!f;
            tot.push_back(sam);
            
        }
        return tot;
    }
};