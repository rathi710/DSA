class Solution {
public:
   int missingNumber(vector<int>& nums) 
   {
        int n=nums.size(),s=0,t;
        t=(n*(n+1)/2);
       
        for(int i=0;i<n;i++){
            s=s+nums[i];
        }
        return t-s;
    }
};



//another interesting approach(math)

 // int missingNumber(vector<int>& nums)
 //    {
 //        int n=nums.size();
 //        sort(nums.begin(),nums.end());
 //        for(int i=0;i<n;i++){
 //            if(nums[i]!= i) return i;
 //        }
 //        return n;
 //    }