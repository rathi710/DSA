class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) 
    {
        int n=A.size();
        vector<vector<int>> ans;
        
        if(A.size() < 3) return {};           //edge case
        
        sort(A.begin(),A.end());
        for(int i=0;i<n-2;i++){
            int l = i+1;
            int r = n-1;
            
            // To avoid duplicates
            if (i > 0 && A[i] == A[i - 1])
                continue;
            
            while(l<r)
            {
                if(A[i]+A[l]+A[r] == 0){                //found it
                    ans.push_back( {A[i],A[l],A[r]} );
                    
                    // Skipping duplicates
                    while (l < r && A[l] == A[l + 1])
                        l++;

                    // Skipping duplicates
                    while (r > l && A[r] == A[r - 1])
                        r--;
                    
                    l++; r--;
                }
                
                else if(A[i]+A[l]+A[r] < 0){
                    l++;
                }
                else r--;
            }
        }
        return ans;
    }
};