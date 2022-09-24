class Solution {
public:
    vector<vector<int>> m;
    void solve(vector<int>nums,vector<int>op, int index)
    {
        if(nums.size() <= index){
            m.push_back(op);
            return;
        }
        
        solve(nums,op,index+1); //not pick
        op.push_back(nums[index]);
        solve(nums,op,index+1); //pick
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>op;
        solve(nums,op,0);
        return m;
    }
};


//
// vector<vector<int> >m;
//     void solve(vector<int>nums,vector<int>op)
//     {
//         if(nums.size()==0){
//             m.push_back(op);
//             return;
//         }
//         vector<int>op1,op2;
//         op1 = op2 = op;
        
//         op1.push_back(nums[0]);
//         nums.erase(nums.begin()+0);
//         solve(nums,op1); //pick
//         solve(nums,op2); //not pick
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int>op;
//         solve(nums,op);
//         return m;
//     }
       