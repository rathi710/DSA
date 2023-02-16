//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        vector<int> tmp = arr;
        vector<int> ans(N);
        sort(tmp.begin(),tmp.end());
        unordered_map<int,int> m;
        int rank=0;
        for(int i=0;i<N;i++){
            if(m.find(tmp[i])==m.end()){
                m[tmp[i]]=rank+1;
                rank+=1;
            }
            
        } 
        for(int i=0;i<N;i++){
            ans[i] = m[arr[i]];
        }
        
        return ans;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends