// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        int n=S.length();
        int start=0,end=1;        //trackers for printing the string
        for(int i=1;i<n;i++){
            
            //for even length of string
            int l=i-1;
            int r=i;
            
            while(l>=0 and r<n and S[l]==S[r]){
                if(r-l+1>end){
                    start=l;
                    end=r-l+1;
                }
                l--;
                r++;
            }
            //for odd length of string
            l=i-1;
            r=i+1;
            
            while(l>=0 and r<n and S[l]==S[r]){
                if(r-l+1>end){
                    start=l;
                    end=r-l+1;
                }
                l--;
                r++;
            }
            
        }
        return S.substr(start, end);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends