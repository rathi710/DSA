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
    
    int check(TreeNode* root, int &flag)
    {
        if(!root) return 1;
        int x = check(root->left,flag);
        int y = check(root->right,flag);
        if(abs(x-y) > 1) flag=0;;
        
        return 1+ max(x,y);
    }
    
    bool isBalanced(TreeNode* root) 
    {
        int flag=1;
        int t = check(root,flag);
        
        return flag;
    }
};