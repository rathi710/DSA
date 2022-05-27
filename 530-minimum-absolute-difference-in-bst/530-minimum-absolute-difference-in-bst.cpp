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
  
    void dfs(TreeNode* root, int &diff, TreeNode* &prev)
    {
        if(!root) return;
        
        dfs(root->left, diff, prev);
        if (prev) diff = min(diff, abs(prev->val - root->val));
        prev = root;
        dfs(root->right, diff, prev);
    }
    
    int getMinimumDifference(TreeNode* root) 
    {
        int diff=INT_MAX;
        TreeNode* prev = NULL;
        
        dfs(root, diff, prev);
        return diff;
    }
};


// Intution- We know that if we somehow get those element in sorted order , our minimum absolute diff. would be one between any two consecutive number right?

// Naive Approach- Just simply do the inorder traversal of BST, Store those element in array/vector, sort it, find min(INT_MAX,abs(v[i]-v[i-1])) , that's it !

// Optimisation-Do we really need to store the element in array? No! Just take prev variable and follow the above mentioned code! Hurray!



//brute force: storing inorder traversal in vector ,then find the difference

//  void helper(TreeNode* root, vector<int>& vec){
//         if(!root)
//         {
//             return;
//         }
//         helper(root->left,vec);
//         vec.push_back(root->val);
//         helper(root->right,vec);
        
//     }
//     int getMinimumDifference(TreeNode* root) {
        
//         vector<int> vec;
//         int mini=INT_MAX;
//         helper(root,vec);
//         for(int i=1;i<vec.size();i++)
//         {
//             mini=min(abs(vec[i]-vec[i-1]),mini);
//         }
//         return mini;
//     }