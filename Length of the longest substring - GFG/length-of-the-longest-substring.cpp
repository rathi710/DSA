//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        int n = S.length();
        // unordered_map<char,int> m;
        int m[256] = {0};
        int left=0,right=0;
        int maxlen=INT_MIN;
        
        while(right < n){
            m[S[right]]++;
            
            while(m[S[right]] > 1){
                m[S[left]]--;
                left++;
            }
            
            maxlen = max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
        
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
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends