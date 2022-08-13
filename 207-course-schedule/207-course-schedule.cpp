class Solution {
public:
    //similar to detect cycle in DAG(directed acyclic graph)
    bool cycle_detect(int s, vector<int>& vis,vector<int>& dfsVis, vector<int> adj[])
    {
        vis[s] = dfsVis[s] = 1;
        
        for(auto it: adj[s]){
            if(!vis[it]){
                if(cycle_detect(it, vis, dfsVis, adj))
                    return true;
            }
            else if(dfsVis[it] == true)
                return true;
        }
        
        // As adj vertices of source are explored, make currVisited as false because we are    coming out of its DFS call
        dfsVis[s] = 0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int n = numCourses;
        vector<int> adj[n];
        for(auto it: prerequisites){
            vector<int> t = it;
            adj[t[0]].push_back(t[1]);
        }
        
        vector<int> vis(n,0), dfsVis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(cycle_detect(i, vis, dfsVis, adj))
                    return false;
            }
        }
        return true;
    }
};

