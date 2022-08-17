class Solution {
public:
    //BFS traversal -> graph
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int fresh=0;   //To keep track of all fresh oranges left
        int time=0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //pushed the rotton oranges
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1) fresh++;  //total oranges
            }
        }
        
        //used for finding all 4 adjacent coordinates
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {-1, 1, 0, 0};
        
        while(!q.empty()){
            int size = q.size();
    
            while(size--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int nx = dx[i] + x;
                    int ny = dy[i] + y;
                    
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        fresh--; // decrement by 1 foreach fresh orange that now is rotten
                    }
                }
            }
            if(!q.empty()) time++;
        }
        if(fresh>0) return -1; //if fresh>0 that means there are fresh oranges left
        return time;
    }
};

// Approach:

// Store position of all initially rotten oranges
// Count all fresh oranges at start
// Start traversing from rotten oranges, go to it's 4 adjacent positions and if the orange is      fresh, then rot it, decrease the count of fresh oranges
// Increase the time after repeating above step for all currently rotten oranges
// At last, if any fresh orange is remaining then return -1, if time is -1 (Didn't start            trsversing) then return 0, else return time taken to rot all oranges
