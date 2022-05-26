/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root) return 0;
        
        //if root is equal to either of p or q, then the other one will definitely be under that
        //root, so root itself is the lca here
        if(root == p or root == q) return root;         
        
        
        //if above is not true, search the left & right subtree of that root
        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);
        
        if(l && r) return root;
        if(l) return l;
        return r;
    }
};