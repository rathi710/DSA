class Solution {
public:
    //similar to detect cycle in DAG(directed acyclic graph) 
    bool dfs(int s, vector<bool>& visited,vector<bool>& dfsVisited, vector<vector<int>>& graph,     vector<bool> &check_cycle)
    {
        visited[s] = true;
        dfsVisited[s] = true;
        
        for(auto it: graph[s]){
            if(!visited[it]){
                if(dfs(it, visited, dfsVisited, graph, check_cycle))
                    return check_cycle[s] = true;
            }
            else if(dfsVisited[it] == true){
                return check_cycle[s] = true;
            }
        }
        
        dfsVisited[s] = false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n,false);
        vector<bool> dfsVisited(n,false);
        vector<bool> check_cycle(n,false);
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, visited, dfsVisited, graph, check_cycle);      
            }
        }
        
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(!check_cycle[i]) ans.push_back(i);
        }
        
        return ans;
    }
};