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
    int idx;
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd,             unordered_map<int,int> &inMap)
    {
        if(inStart > inEnd) return 0;
        TreeNode* root = new TreeNode(preorder[idx++]);
        
        if(inStart == inEnd) return root;
        
        int mid = inMap[root->val];
        
        root->left = solve(preorder,inorder,inStart,mid-1,inMap);
        root->right = solve(preorder,inorder,mid+1,inEnd,inMap);
        return root;   
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int n=inorder.size();
        idx = 0;
        unordered_map<int,int> inMap;
        
        for(int i=0; i<n; i++) inMap[inorder[i]]=i;
        TreeNode* root = solve(preorder,inorder,0,n-1,inMap);
        return root;
    }
};

//codelibrary