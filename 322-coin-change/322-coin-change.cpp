class Solution {
public:
    
    
    
    
    int findLowestCoins(vector<int> &coins, int n, int amount) 
    {
        int dp[n + 1][amount + 1];
        
        //initialization
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= amount; j++){
                
                if (j == 0) dp[i][j] = 0;
                if (i == 0) dp[i][j] = INT_MAX - 1;
            }
        }
                    
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
        }
        
        return dp[n][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        int res = findLowestCoins(coins, coins.size(), amount);
        return (res == INT_MAX - 1) ? -1 : res;
    }
};