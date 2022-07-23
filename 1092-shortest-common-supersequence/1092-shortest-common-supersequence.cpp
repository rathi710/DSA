class Solution {
public:
    
    string shortestCommonSupersequence(string s1, string s2) 
    {
        int r=s1.length(), c=s2.length();

        vector<vector<int>> dp(r+1,vector<int>(c+1,0));
        
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                
            }
        }
        
        string scs = "";
        int i = r, j = c;
        
        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                scs += s1[i-1];
                i--; j--;
            }
            else if(dp[i][j-1] > dp[i-1][j]){
                scs += s2[j-1];
                j--;
            }
            else{
                scs += s1[i-1];
                i--;
            }
        }
        
        while(i > 0){
            scs += s1[i-1];
                i--;
        }
        while(j > 0){
            scs += s2[j-1];
                j--;
        }
        
        reverse(scs.begin(),scs.end());
        return scs;
    }
};