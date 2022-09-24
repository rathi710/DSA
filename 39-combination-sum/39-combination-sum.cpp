class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& arr, int target, vector<int>tmp, int idx){
        if(idx >= arr.size()){
            if(target == 0){
                ans.push_back(tmp);
            }
            return;
        }
        
        if(arr[idx] <= target){
            tmp.push_back(arr[idx]);
            //idx same bcoz we can pick same element again
            helper(arr, target-arr[idx], tmp, idx); 
            tmp.pop_back();  //backtrack
        }
        
        //not pick
        helper(arr, target, tmp, idx+1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> tmp;
        helper(arr,target,tmp,0);
        return ans;
    }
};