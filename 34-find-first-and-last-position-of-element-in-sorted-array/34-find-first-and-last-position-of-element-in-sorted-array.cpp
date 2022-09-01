class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n=nums.size();
        int l=0,r=n-1;
        int res1=-1;
        
        //for first occurence
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                res1=mid;
                r=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        
         //for second occurence
        l=0,r=n-1;
        int res2=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                res2=mid;
                l=mid+1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return {res1,res2};
    }
};