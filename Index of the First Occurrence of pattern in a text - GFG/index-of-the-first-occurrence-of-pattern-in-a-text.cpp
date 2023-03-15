//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMatching(string text, string pat) {
        int t = text.size(), p = pat.size();
        // Code here
        int i=0,j=0;
        int cnt=0;
        
        while(i < t && j < p){
            if(pat[j] != text[i]) i++;
            else{
                while(pat[j] == text[i]){
                    i++;j++;
                    if(j==p) return i-pat.size();
                }
                i=i-j+1;
                j=0;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    }
    return 0;
}
// } Driver Code Ends