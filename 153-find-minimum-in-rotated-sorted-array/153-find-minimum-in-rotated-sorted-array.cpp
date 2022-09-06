class Solution {
public:
    int findMin(vector<int>& nums) {
         int n = nums.size();
        
        if(n==1)
            return nums[0];
        
        //if array is sorted then first element is smallest
        if(nums[0] < nums[n-1])
            return nums[0];
        
        int start = 0;
        int end = n-1;
        
        while(start <= end){
            
            int mid = (start + end) / 2;
			
            if(nums[mid]>nums[mid+1]) return nums[mid+1];
            
            else if(nums[mid] >= nums[0])
                start = mid +1;
            else{
                end = mid - 1;
            }
        }
        return -1;
    }
};