class Solution {
public:
    //dp tabulation
    int countSquares(vector<vector<int>>& matrix)
    {
        int n=matrix.size(); //row
        int m=matrix[0].size(); // col
        
        //making dp table 
        vector<vector<int>> dp(n, vector<int>(m));
        int count=0;
        
        
        // A SINGLE ELEMENT represents 1 square side existence
        
        
        //Which row is not responsible for any major changes in count ?
        //Ans: ROW 0
        // filling row 0 and adding all its values to the count
        for(int i=0;i<m;++i)
        {
            dp[0][i]=matrix[0][i];
            count+=dp[0][i];
        }
        
        //Which col is not responsible for any major changes in count ?
        //Ans: COL 0
        // filling col 0 and adding all its values to the count
        for(int i=1;i<n;i++)
        {
            dp[i][0]=matrix[i][0];
            count+=dp[i][0];
        }
        
        
        //now rest are matrix calulated 
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                // I've to take min from all above direction of the current index, as their MAY/ MAY NOT be square side formation count.
                if(matrix[i][j]==1) 
                    dp[i][j]= 1+ min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
                else 
                    dp[i][j] = 0;
                    
                count+=dp[i][j];
                
             }
        }
        
        return count;
    }
};





//MEMOIZATION:-

// int dp[301][301];
//     int solve(vector<vector<int>>& matrix, int i, int j){
//         if(i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] == 0) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         int cur_ans;
// cur_ans = 1 + min(solve(matrix, i + 1, j), min(solve(matrix, i, j + 1), solve(matrix, i + 1, j + 1)));
//         return dp[i][j] = cur_ans;
        
//     }
//     int countSquares(vector<vector<int>>& matrix) {
//           int ans = 0;
//           int row = matrix.size();
//           int col = matrix[0].size();
//           memset(dp, -1, sizeof(dp));
//           for(int i = 0; i < row; i++){
//               for(int j = 0; j < col; j++){
//                    if(matrix[i][j] == 1){
//                        ans += solve(matrix, i, j);
//                    }
//               }
//           }
//         return ans;
//     }