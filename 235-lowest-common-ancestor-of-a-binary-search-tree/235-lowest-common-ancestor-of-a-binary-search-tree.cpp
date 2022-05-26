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
        
        
       // we'll call both side of the current node and if both value comes as not null value that        //means below the current node both the nodes (p,q) exists
        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);
        if(l && r) return root;
        
        //if above condition is not satisfy then we'll check which node returned as not null we'll         //just return that
        if(l) return l;
        return r;
    }
};


