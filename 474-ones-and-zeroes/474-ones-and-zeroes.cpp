class Solution {
public:
    //memoization
    
    int dp[601][101][101];
    int fun(int i,int m, int n, vector<string> &s)
    {
	   // base case
        if(i >= s.size() || n<0 || m<0 ){
            return 0;
        }
        
		// simply return the value if previously calculated
        if(dp[i][m][n] != -1)return dp[i][m][n];
        
        int c0 = count(s[i].begin(),s[i].end(),'0');
        int c1 = count(s[i].begin(),s[i].end(),'1');
        
		// if we can take this string , then ans_till_here = max(take it , avoid it)
        if(m-c0 >= 0 && n-c1 >= 0 )
        return dp[i][m][n] = max(fun(i+1,m-c0,n-c1,s)+1, fun(i+1,m,n,s));
        
		//otherwise avoid it
        else return dp[i][m][n] = fun(i+1,m,n,s);
    }
    
    int findMaxForm(vector<string>& s, int m, int n) {
        int sz = s.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,m,n,s);
    }
};





//recursion:-
// int solve(vector<string>& strs, int m, int n, int index){
//         if(index == strs.size()) return 0;
        
//         int nZeros = count(strs[index].begin(),strs[index].end(),'0');
//         int nOnes = strs[index].size() - nZeros;
        
//         if(m - nZeros >= 0 && n - nOnes >=0)
//             return max(1 + solve(strs, m-nZeros, n-nOnes, index+1), solve(strs,m,n,index+1));
//         else
//             return solve(strs, m, n, index+1);
//     }
    
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         return solve(strs,m,n,0);
//     }