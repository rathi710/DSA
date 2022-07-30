class Solution {
public:
    int solve(vector<vector<int>> &dp, int i, int j)
    {
        dp[0][0] = 1;
        if(i < 0 || j < 0){
            // dp[i][j] = 0;
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int left = solve(dp, i , j-1) ;
        int up = solve(dp, i-1 , j);
        
        return dp[i][j] = left + up ;
    }
    
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m,vector<int>(n,-1)); //dp initialization
        return solve(dp, m-1, n-1);
    }
};

