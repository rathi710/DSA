class Solution {
public:
    //binary search(logn)
    int searchInsert(vector<int>& nums, int target) {
        int ans=0;
        int n=nums.size();
        
        int start=0, end = n-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target){
                ans = mid+1;
                start = mid+1;
            }
            else end = mid-1;
        }
        return ans;
    }
};