class Solution {
public:
    //dfs
    unordered_map<int,vector<int>> m;
    int mx=0, ans=0;
    
    void dfs(int manager, vector<int>& informTime){
        mx = max(mx,ans);
        
        for(auto it: m[manager]){
            ans += informTime[manager];
            dfs(it,informTime);
            
            ans -= informTime[manager];
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {    
        for(int i=0; i<n; i++){
            if(manager[i] != -1){
                m[manager[i]].push_back(i);
            }
        }
        
        dfs(headID,informTime);
        
        return mx;
    }
};