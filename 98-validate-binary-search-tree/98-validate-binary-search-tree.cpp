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
        
        //-1/+1 or = in above base case bcoz no two values can be same in a bst
        //every node is unique
        return helper(root->left,min,root->val) && helper(root->right,root->val,max);
    }
    
    bool isValidBST(TreeNode* root) 
    {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

//above: Range based Approach

//another approach: using inorder traversal

//we will do inorder traversal which will be sorted if its a BST
//maintain a prev pointer and check along the way that prev should be smaller than the current root

//  void fun(Node*root,Node* &prev,int &f){
         
//         if(!root) return;
//         fun(root->left,prev,f);
//         if(prev && prev->data>=root->data){
//             f = 0;
//             return;
//         }
//         prev = root;
//         fun(root->right,prev,f);
//     }
    
//     bool isBST(Node* root) 
//     {
//        Node*prev = NULL;
//        int f = 1;
//        fun(root,prev,f);
//        return f;
//     }