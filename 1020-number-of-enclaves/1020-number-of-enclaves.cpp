class Solution {
public:
    //Boundary DFS
    //similar to surrounded regions
    bool isValid(int i, int j, vector<vector<int>>& grid, int n, int m){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == 1){
            return true;
        }
        return false;
    }
    
    void dfs(int i, int j, vector<vector<int>>& grid, int n, int m){
        grid[i][j] = 0;
        
        if(isValid(i+1,j,grid,n,m)) dfs(i+1,j,grid,n,m);
        if(isValid(i-1,j,grid,n,m)) dfs(i-1,j,grid,n,m);
        if(isValid(i,j-1,grid,n,m)) dfs(i,j-1,grid,n,m);
        if(isValid(i,j+1,grid,n,m)) dfs(i,j+1,grid,n,m);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++){
            // left: top->bottom
            if(grid[i][0] == 1){
                dfs(i,0,grid,n,m);
            }
            
            //right: top->bottom
            if(grid[i][m-1] == 1){
                dfs(i,m-1,grid,n,m);
            }
        }
        for(int j=0; j<m; j++){
            // top: left->right
            if(grid[0][j] == 1){
                dfs(0,j,grid,n,m);
            }
            
            //bottom: left->right
            if(grid[n-1][j] == 1){
                dfs(n-1,j,grid,n,m);
            }
        }
        
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};