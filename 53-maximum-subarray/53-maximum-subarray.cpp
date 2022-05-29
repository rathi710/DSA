class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum=0;
        int bestSum=INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            currentSum=max(nums[i],currentSum+nums[i]);
            bestSum=max(bestSum,currentSum );
            
        }
        return bestSum;
    }
};