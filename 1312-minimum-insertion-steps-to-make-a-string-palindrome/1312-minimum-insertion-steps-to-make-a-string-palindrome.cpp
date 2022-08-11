class Solution {
public:
    
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>> dp(x+1,vector<int>(y+1,0));
        
        for(int i=1; i<=x; i++){
            for(int j=1; j<=y; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[x][y];
        
    }
    
    int minInsertions(string s) {
        int n = s.length();
        string sr = s;
        reverse(s.begin(),s.end());
        return n - lcs(n,n,s,sr);
    }
};