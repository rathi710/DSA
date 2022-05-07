class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
       int n=nums.size();
       unordered_map<int,int> m;
       
        for(int i=0;i<n;i++)
        {
            int curr=target-nums[i];
            
            if(m.find(curr)!=m.end() and m[curr] != i)  //found the ele
            {
                return {i, m[curr]};
            }
            
             m[nums[i]] = i;   //keep inserting what we have seen
        }
        
        return {};  //pair not found
    }
};


//using hashmap
//tc->o(n)
//sc->o(n)