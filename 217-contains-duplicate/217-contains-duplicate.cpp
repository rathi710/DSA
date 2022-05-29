class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=1;
        while(j<=n-1){
            if(nums[i]==nums[j]) return true;
            i++;
            j++;
        }
        return false;
    }
};