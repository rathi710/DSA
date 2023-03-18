//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
        vector<int> fillLPS(string &pat){
            int n = pat.length();
            vector<int> lps(n);
            int len = 0, i = 1;
            lps[0] = 0;

            while(i < n){
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
            return lps;
        }
        
        
    int minChar(string s){
        //Write your code here
         int n = s.size();
        string rev = s;
        reverse(rev.begin(),rev.end());
        string c = s + "#" + rev;
        
        vector<int> lps = fillLPS(c);
        return n-lps.back();
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends