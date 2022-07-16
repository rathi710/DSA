class Solution {
public:
   int subsetSum(vector<int> arr, int n, int total)
    {
        int t[n+1][total+1];
        
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < total+1; j++)
            {
                if(i == 0)
                    t[i][j] = false;
                if(j == 0)
                    t[i][j] = true;
            }
        }
        
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < total+1; j++)
            {
                if(arr[i-1] <= j)
                    t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][total];
    }
    
    bool canPartition(vector<int>& nums) 
    {    
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        
        if(sum % 2 != 0)
            return false;
        
        return subsetSum(nums, nums.size(), sum/2);  
    }
};