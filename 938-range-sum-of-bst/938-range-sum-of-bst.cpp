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
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        if(!root) return 0;
        int sum=0;
        
        if(root->val > low){
            sum += rangeSumBST(root->left,low,high);
        }
        if(root->val >= low && root->val <= high){
            sum += root->val;
        }
        if(root->val < high){
            sum += rangeSumBST(root->right,low,high); 
        }
        
        return sum;
    }
};

//above is the optimised approach: here we utilizing the property of bst that nodes left to root are all smaller & to the right are bigger.

//Brute force: It can be to travarse all the nodes & check if fits the condition using dfs.