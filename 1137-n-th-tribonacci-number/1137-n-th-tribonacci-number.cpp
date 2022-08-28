class Solution {
public:
    //tabulation
    int tribonacci(int n) {
        int dp[40];
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
};



//using Recurssion(TLE)
// int tribonacci(int n) {
//         if(n==0) return 0;
//         if(n==1 || n==2) return 1;
        
//         return tribonacci(n-1)+ tribonacci(n-2)+ tribonacci(n-3);
//     }