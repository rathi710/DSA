class Solution {
public:
    //just use a set after sorting
    vector<vector<int>> m;
    set<vector<int>> s;
    void solve(vector<int>nums,vector<int>op, int index)
    {
        if(nums.size() <= index)
        {
            if(s.find(op)==s.end()){
                s.insert(op);
                m.push_back(op);
            }
            return;
        }
        
        solve(nums,op,index+1); //not pick
        op.push_back(nums[index]);
        solve(nums,op,index+1); //pick
    }
   
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>op;
        sort(nums.begin(),nums.end());
        solve(nums,op,0);
        return m;
    }
};