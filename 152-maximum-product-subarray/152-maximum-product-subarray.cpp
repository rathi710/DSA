class Solution {
public:
    //by dynamic programming
    int maxProduct(vector<int>& nums) 
    {
       int r=nums[0];
       int maxi=r;
       int mini=r;
       for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                swap(maxi,mini);
            }
            maxi=max(nums[i],nums[i]*maxi);
            mini=min(nums[i],nums[i]*mini);
            r=max(r,maxi);
        }
        return r;
    }
};



//kadane algo
// int maxProduct(vector<int>& nums) 
//     {
//         int n=nums.size();
//         int product=1;
//         int max_product=INT_MIN;
        
//         for(int i=0;i<n;i++)
//         {
//             product*=nums[i];
//             max_product=max(product,max_product);
//             if(product==0)
//                 product=1;
//         }
        
//         product=1;
//         for(int i=n-1;i>=0;i--)
//         {
//             product*=nums[i];
//             max_product=max(product,max_product);
//             if(product==0)
//                 product=1;
//         }
        
//         return max_product;
//     }


//brute force(N^2)
// int maxProduct(vector<int>& nums) {
//         int ans = INT_MIN; mul;
//         for(int i=0;i<nums.size();i++)
//         {
//             mul= nums[i];
//             ans = max(ans,mul);
//             for(int j= i+1;j<nums.size();j++)
//             {
//                 mul *= nums[j];
//                 ans= max(ans,mul);
//             }
//         }
//         return ans;
//     }