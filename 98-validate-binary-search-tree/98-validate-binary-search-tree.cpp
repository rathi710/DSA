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
    bool helper(TreeNode* root, long min, long max)
    {
        if(!root) return true;
        if(root->val <= min || root->val >= max) return false;
        
        //-1/+1 bcoz no two values can be same in a bst
        //every node is unique
        return helper(root->left,min,root->val) && helper(root->right,root->val,max);
    }
    
    bool isValidBST(TreeNode* root) 
    {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};