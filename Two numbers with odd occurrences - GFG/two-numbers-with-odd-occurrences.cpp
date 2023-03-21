//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        long long int t = Arr[0];
        
        for(int i=1;i<N;i++){
            t = t ^ Arr[i];
        }
        
        long long int right_bit = t & ~(t-1);
        long long int x=0,y=0;
        
        for(int i=0;i<N;i++){
            if(right_bit & Arr[i]){
                x = x ^ Arr[i];
            }
            else y = y ^ Arr[i];
        }
        
        if(x>y) return {x,y};
        return {y,x};
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends