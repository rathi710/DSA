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
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int flag=0;
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> tmp;
            
            while(size--){
                TreeNode* t = q.front();
                q.pop();
                tmp.push_back(t->val);
                
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            
            if(flag == 1) reverse(tmp.begin(),tmp.end());
            ans.push_back(tmp);
            flag=!flag;
        }
        return ans;
    }
};