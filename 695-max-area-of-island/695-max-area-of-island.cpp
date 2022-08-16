class Solution {
public:
    
    //checking if the indexes are getting out of bound or not
    bool isValid(int i,int j,int r,int c,vector<vector<int>> &grid)
    {
        if(i>=0 && i<r && j>=0 && j<c && grid[i][j]==1) return true;
        return false;
    }
    
    //make the visited 0, and call dfs recursion for other,
    //we get one island after this
    void solve(int i,int j,int r,int c,vector<vector<int>> &grid, int& area)
    {
         area++;
         grid[i][j]=0;
        
         if(isValid(i+1,j,r,c,grid))
            solve(i+1,j,r,c,grid,area);
        
         if(isValid(i-1,j,r,c,grid))
            solve(i-1,j,r,c,grid,area);
             
         if(isValid(i,j+1,r,c,grid))
            solve(i,j+1,r,c,grid,area);
              
         if(isValid(i,j-1,r,c,grid))
            solve(i,j-1,r,c,grid,area); 
            
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans=0;
        
        //searching for 1 in matix to begin our journey for searcing island 
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1){       
                    int area=0;
                    solve(i,j,r,c,grid,area);
                    ans = max(ans,area);
                }
            }
        }
        return ans;
    }
};
//dfs: variation of no of islands