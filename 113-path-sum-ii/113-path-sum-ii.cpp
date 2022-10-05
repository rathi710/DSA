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
    vector<vector<int>> ans;
    void solve(TreeNode*root,int sum,vector<int>tmp)
    {
        if(!root) return;
        tmp.push_back(root->val);
        
        if(!root->left && !root->right && sum-root->val == 0){
            ans.push_back(tmp);
            tmp.clear();
            return;
        }
        solve(root->left,sum-root->val,tmp);
        solve(root->right,sum-root->val,tmp);
        tmp.pop_back();  //backtrack
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> tmp;
        solve(root,targetSum,tmp);
        return ans;
    }
};