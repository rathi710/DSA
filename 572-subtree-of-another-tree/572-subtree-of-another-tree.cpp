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
    
    bool isSame(TreeNode* p, TreeNode* q)
    {
        //if any of the tree is null then there is no need to compare
        if(!p or !q) return (p==q);
        
        //now since both are not null check if they have same value otherwise return false
        if(p->val != q->val) return false;
        
        //if value is same then check if both its left and right sub-tree are same
        return isSame(p->left,q->left) && isSame(p->right,q->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(!root && !subRoot) return true;
        if(!root or !subRoot) return false;
        
        //check if s and t are same, if yes return true
        if(isSame(root,subRoot)) return true;
        
        //if s and t are not same then pass left and right nodes, and check same for that nodes as well as its           //child nodes.
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};