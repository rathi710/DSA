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
    
    int solve(TreeNode* root,int &ans){
        if(!root) return 0;
        int l = solve(root->left,ans);
        int r = solve(root->right,ans);

        ans = max(ans,l+r);
        return 1 + max(l,r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(!root) return 0;
        int ans=-1;
        int x = solve(root,ans);
        return ans;
    }
};