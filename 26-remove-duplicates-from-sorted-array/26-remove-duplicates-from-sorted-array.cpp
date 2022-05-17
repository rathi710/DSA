class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        
        //initialise the last index of new vector
        
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[i]!=nums[j])  {
                i++; 
                nums[i]=nums[j];
            }
        }
        
        //return the size of the new vector which size index+1
        return i+1;
        
        
    }
};