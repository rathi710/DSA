// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<bool> visited(V,false);
        vector<int> distance(V,INT_MAX);
       
       distance[S] = 0;
       
       for(int cnt=0;cnt<V;cnt++)
       {
           int mini = INT_MAX, ind;
           for(int i=0; i<V; i++){
               if(!visited[i] && distance[i] < mini){
                   mini = distance[i];
                   ind = i;
               }
           }
           
           visited[ind] = true;
           
           for(auto ele : adj[ind]){
                if(!visited[ele[0]]){
                    int dist = distance[ind] + ele[1];
                    distance[ele[0]] = min(distance[ele[0]], dist);
                }
           }
         
       }
       return distance;
   }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends