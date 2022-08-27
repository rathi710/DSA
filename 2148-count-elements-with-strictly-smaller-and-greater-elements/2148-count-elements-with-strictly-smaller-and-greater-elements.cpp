class Solution {
public:
    int countElements(vector<int>& nums) 
    {
        int mn=INT_MAX;
        int mx=INT_MIN;
        int ans=0;

        for(int i=0;i<nums.size();i++){
            mn = min(mn,nums[i]);
            mx = max(mx,nums[i]);
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]>mn && nums[i]<mx){
                ans++;
            }
        }
        return ans;
    }
};
//can use sorting also to get the smallest and greatest element