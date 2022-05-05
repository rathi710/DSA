class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int n=nums.size();
        
        int i =0,k = n-1,j = 0;
        while(j<=k)
        {
            if(nums[j]==0)    swap(nums[i++],nums[j++]);
            else if (nums[j]==1)   j++;
            else if(nums[j]==2)   swap(nums[j],nums[k--]);
        }
    }
};

//using dutch national flag algo