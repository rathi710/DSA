// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {   
        //step 1 - push all the elements in the stack
        stack<int> st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        //step 2 - pop 2 elements and check if if like a know b,then push b again 
        //coz a can never be a celebrity
        //element that remains at last is a potential candidate
        while(st.size()>1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if(M[a][b]==1) st.push(b);
            else st.push(a);
        }
        
        int candidate=st.top();
        // step 3 - confirm this element from matrix(row=all 0 and its column=all 1 except 1)
        for(int i=0;i<n;i++){
            if(M[candidate][i]!=0) return -1;
        }
        
        int c=0;
         for(int i=0;i<n;i++){
            if(M[i][candidate]==1) c++;
        }
        
        if(c!=n-1) return -1;
        return candidate;
    }  
};

//optimised-O(N)->done above

//brute force-> O(N^2)

//  int celebrity(vector<vector<int> >& M, int n) 
//     {   
//         int in[n] = {0};
//         int out[n] = {0};
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(M[i][j] == 1){
//                     in[j]++;
//                     out[i]++;
//                 }
//             }
//         }
//         for(int i=0;i<n;i++){
//             if(in[i] == n-1 and out[i] == 0){ 
//               return i;
//             }
//         }
//         return -1;
//     }

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends