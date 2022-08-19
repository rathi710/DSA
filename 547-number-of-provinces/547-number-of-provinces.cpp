class Solution {
public:
    //simple DFS problem
    void dfs(int s, vector<bool> &vis, vector<int> adj[]){
        vis[s] = true;
        for(auto it: adj[s]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        
        //modifying adj matrix acc to my needs
        vector<int>adj[n];
        
        for(int i=0;i<n;i++){
            vector<int>p = isConnected[i];
            for(int j=0;j<n;j++){
                if(p[j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                } 
            }
        }
        //just do simple DFS
        vector<bool> vis(n,false);
        int cnt=0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};