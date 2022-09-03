class Solution {
public:
    //Greedy : o(n) : efficient
    //start from last index & check if we can reach that index from the prev index
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int index = n-1;
        for(int i=n-1; i>=0; i--){
            if(i+nums[i] >= index){
                index = i;
            }
        }
        if(index == 0) return true;
        return false;
    }
};


//DP : o(n^2)
// bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         vector<bool> dp(n+1);
//         dp[n-1] = true;
//         for(int i=n-2; i>=0; i--){
//             for(int k=0; k<=nums[i]; k++){
//                 if(dp[i+k] == true){
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }
//         return dp[0];
//     }


//Recursion : TLE : o(2^n)
//  bool rec(vector<int>& nums, int idx){
//         int n = nums.size();
//         //if you are already on the last step return true
//         if(idx == n-1) return true;
        
//         for(int i=1; i<=nums[idx]; i++){
//             if(idx+i < n && rec(nums,idx+i))
//                 return true;
//         }
//         return false;
//     }
    
//     bool canJump(vector<int>& nums) {
//         return rec(nums,0);
//     }