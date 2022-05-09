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
            
            // To avoid duplicates by incrementing i
            if (i > 0 && A[i] == A[i - 1])
                continue;
            
            // Keeping A[i] same, check for sum of triplets=0 
            // from i+1 till the end of nums vector
            while(l<r)
            {
                if(A[i]+A[l]+A[r] == 0){                //found it
                    ans.push_back( {A[i],A[l],A[r]} );
                    
                    // To skip duplicate elements at left pointer
                    while(l<r && A[l]==A[l+1]) 
                        l++;
                    
                    // To skip duplicate elements at left pointer
                    while(l<r && A[r]==A[r-1]) 
                        r--;
                    // One unique triplet has been found.
                    // Increment left & decrement right for  
                    // next triplet to be unique
                    
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