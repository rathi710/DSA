class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> ans;
        int n=nums.size();
        
        for(auto x:nums)
        {
            x= abs(x);
            if(nums[x-1]>0) nums[x-1] *= -1;
            else ans.push_back(x);
        }
        
        return ans;
    }
};

//interesting concept
//most efficient o(n) solution with no extra space.
//https://leetcode.com/problems/find-all-duplicates-in-an-array/discuss/1682530/C%2B%2B-Multiple-approaches-explained-with-full-explanation!