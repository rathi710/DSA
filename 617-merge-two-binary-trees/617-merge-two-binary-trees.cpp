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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(!root1) return root2;   //attach other if one root is null
        if(!root2) return root1;
        
        root1->val += root2->val;   //both root exist -> add them
        root1->left = mergeTrees(root1->left, root2->left);    //go left in both trees
        root1->right = mergeTrees(root1->right, root2->right);   //go right
        
        return root1;
    }
};