//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
       void fillLPS(string &pat, int *lps, int M){
            // int n = pat.length();

            int len = 0, i = 1;
            lps[0] = 0;

            while(i < M){

                if(pat[i] == pat[len]) {
                    lps[i] = len+1;
                    len++; i++;
                    
                }
                else{
                    if(len == 0) {
                        lps[i] = 0;
                        i++; 
                        
                    }
                    else len = lps[len-1]; 
                }
            }
        }

        vector <int> search(string pat, string txt)
        {
            //code here.
            int N = txt.length();
            int M = pat.length();

            int lps[M];

            fillLPS(pat, lps, M);
            int i = 0, j = 0;
            vector<int> ans;

            while(i < N){
                if(pat[j] == txt[i]) {
                    i++; j++; 
                }
                if(j == M) { 
                    ans.push_back(i-j+1); 
                    j = lps[j-1]; 
                    
                }
                else if(i < N  and pat[j] != txt[i]){
                    if(j == 0) i++;
                    else j = lps[j-1]; 
                }
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends