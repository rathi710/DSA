// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
  void dfs(int i,vector<bool> &visited,vector<int> adj[],vector<int> &ans)
  {
      visited[i]=true;
      ans.push_back(i);
      
      for(auto x: adj[i]){
          if(visited[x]==false){
              dfs(x,visited,adj,ans);
          }
      }
  }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<int> ans;
        vector<bool> visited(V,false);
        
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                dfs(i,visited,adj,ans);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends