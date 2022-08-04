class Solution {
public:
    //variation of LCS(dynamic programming)
    int solve(vector<int>& nums1, vector<int>& nums2, int n1, int n2, vector<vector<int>> dp)
    {
        int ans=0;
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(nums1[i-1] == nums2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2= nums2.size();
        
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        return solve(nums1,nums2,n1,n2,dp);
    }
};