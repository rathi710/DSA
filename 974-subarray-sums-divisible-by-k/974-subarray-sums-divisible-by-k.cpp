class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        // taking a map to store the key as a remainder and value as its fequency
        
        unordered_map<int, int> mp;  
        mp[0] = 1;                      //initially reminder will be 0
        int sum = 0, ans = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            sum += nums[i];
            
            // finding the remainder of the sum
            int rem = sum % k;
            
            // to handle the negative rem case, i.e nums[-1,2,9], k = 2
            // whenver rem is less than 0, then add k into it to amke rem +ve again
            
            if(rem < 0) rem += k;
            
            // add the frequency of rem into ans
            
            if(mp.find(rem)!=mp.end()){
                ans += mp[rem];
            }
            
            // increase the frequency of rem into map by 1
            mp[rem]++;
        }
        return ans;
    }
};