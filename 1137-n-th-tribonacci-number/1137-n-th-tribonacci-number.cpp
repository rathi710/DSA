class Solution {
public:
    //tabulation
    int tribonacci(int n) {
        int dp[n+1];
        if(n==0) return 0;
        if(n <=2) return 1;
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

// Time Complexity : O(2^N).This is the most naive approach to calculate tribonacci number and recursion tree grows exponentially. There's a lot of repeated work that happens here.
    


//implemented above:-
//Since the previous solution does a lot of repeated calculcations, we can optimize the approach by storing calculated results and returning them instead of recalculating them again and again.