class Solution {
public:
     int countHousePlacements(int n) 
     {
        vector<long long> dp(n + 1);
        int mod = 1e9 + 7;
        dp[0] = 1, dp[1] = 2;
         
        for (int i = 2; i <= n; ++i)
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
         
        return dp[n] * dp[n] % mod;
    }
};


// I did not realize it at first, but placement on one side does not affect the other.

// So, we can just count number arrangements on one side, and return the square of that number.

// Counting arrangement is similar to 198. House Robber, but here it's simpler as we do not have to rob those houses, only count.