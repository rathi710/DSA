class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        vector<int> pairs;
        int n1=spells.size();
        int n2=potions.size();
        
        //to do the binary search to reduce tc
        //Binary search the index of first potion >= need in the sorted potions.
        // The number of potions that are successful are potions.length() - idx
        sort(potions.begin(),potions.end()); 
        
        for(int k=0; k<n1; k++)
        {
            int i=0, j=n2-1;
            int idx = -1;
            
            while(i<=j){
                int mid = i +(j-i)/2;
                long long x = (long long)spells[k] * (long long)potions[mid];
            
                if(x >= success){
                    idx = mid;
                    j = mid - 1;
                }
                else{
                    i = mid + 1;
                }
            }
            
            if(idx==-1) pairs.push_back(0);
            else pairs.push_back(n2 - idx);
        }
        
        return pairs;
    }
};