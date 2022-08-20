class Solution {
public:
    //2 time calling dfs=boundary dfs to deal with boundary associated land & other to count the
    //number of connected components of lands(0's) 
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid){
        grid[i][j] = 1;
        
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        for(int k=0; k<4; k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0){
                dfs(nx,ny,n,m,grid);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i*j == 0 || i == n-1 || j == m-1){
                    
                    if(grid[i][j] == 0)
                        dfs(i,j,n,m,grid);
                }
            }
        }
        
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    cnt++;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        
        return cnt;
    }
};