class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
       unordered_map <int,int> ump;
        
        vector <int> ans;
        for(int i=0;i<nums.size();i++){
            ump[nums[i]]++;
        }
        
        for(auto i : ump){
            if(i.second == 2)
                ans.push_back(i.first);
            
        }
        return ans;
    }
};