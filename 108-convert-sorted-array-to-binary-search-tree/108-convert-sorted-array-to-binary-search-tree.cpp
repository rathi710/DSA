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
    
    TreeNode* createBST(vector<int>& nums,int low,int high)
    {
        if(low > high) return 0;
        
        int mid = (low + high)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = createBST(nums,low,mid-1);
        root->right = createBST(nums,mid+1,high);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        int n=nums.size();
        int low=0;
        int high=n-1;
        
        return createBST(nums,low,high);

    }
};



//ALGORITHM:

//1 - Get the Middle of the array and make it root.
//2 - Recursively do same for left half and right half.
//    a) Get the middle of left half and make it left child of the root created in step 1.
//    b) Get the middle of right half and make it right child of the root created in step 1.
