class Solution {
public:
    //dp on 3d matrix(memoization)
    double helperFunction(int N, int K, int r, int c, vector<vector<vector<double>>> & dp)
    {
        if(r < 0 || c < 0 || r >= N || c >= N) return 0;
        if(K == 0) return 1;
        
        if(dp[r][c][K] != -1) return dp[r][c][K];
        
        double sum = helperFunction(N, K - 1, r - 2, c - 1, dp) +
                     helperFunction(N, K - 1, r - 1, c - 2, dp) +
                     helperFunction(N, K - 1, r + 1, c - 2, dp) +
                     helperFunction(N, K - 1, r + 2, c - 1, dp) +
                     helperFunction(N, K - 1, r - 2, c + 1, dp) +
                     helperFunction(N, K - 1, r - 1, c + 2, dp) +
                     helperFunction(N, K - 1, r + 1, c + 2, dp) +
                     helperFunction(N, K - 1, r + 2, c + 1, dp);
        
        sum /= 8;
        return dp[r][c][K] = sum;
    
    }
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(N + 1, vector<vector<double>> (N + 1, vector<double>(K + 1, -1)));
        return helperFunction(N, K, r, c, dp);
    }
    
};



// Explanation:-
// The idea is, we have a knight and it has to move in 8 directions and it has k moves in total. Also, in question it is given that, it will continue moving until k becomes 0 or knight moves off the chessboard. And, we need to find the probabilitiy that knight remains on the board after it has stopped moving.

// Now, If you look at the problem, it generally talks about the path and exploration and stuff like that. Whenever, we talk related to exploring all the path then we should think about resursion.

// Now, we have decided that we are going to use recursion and we will be exploring all the paths. So, possible path for the knight is going to be given below, when the knight is at (x, y) from there it will move,

// (row-2, column -1)
// ( row-1, column -2)
// ( row+2, column +1)
// ( row+1, column +2)
// ( row-2, column +1)
// ( row+2, column -1)
// ( row-1, column +2)
// ( row+1, column -2)
// in these many directions.
    
// Now, let's talk about the probability, Since knight has to move in 8 directions, for one move of knight the probability will be 1/8.

// Also, let's talk about the base case:

// Check if the position is valid or not if not return 0.
// Check if k == 0 or not, if k is 0 then there is no movement from knight and Probability of knight on the borad is 1.
