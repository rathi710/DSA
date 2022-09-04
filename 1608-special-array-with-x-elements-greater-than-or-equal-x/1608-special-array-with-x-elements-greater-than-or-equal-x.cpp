class Solution {
public:
    //binary - search
    int specialArray(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        for(int i = 0; i <= n; i++)
        {
            int temp = n;
            int l = 0, h = n-1;
            
             while(l <= h){
                 int mid=l+(h-l)/2;
                 
                 if(nums[mid]>=i){
                     temp=mid;
                     h=mid-1;
                 }
                 else l=mid+1;
             }
             if((n-temp)==i) return i;
        }
        return -1;
    }
};


//brute-force
// int specialArray(vector<int>& nums) {
//         for(int i=1; i<10001; i++){
//             int c=0;
//             for(int j=0; j<nums.size(); j++){
//                 if(nums[j] >= i) c++;
//             }
//             if(i == c) return i;
//         }
//         return -1;
//     }