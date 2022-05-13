class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1=nums1.size();
        int n2=nums2.size();
        
        int k=(n1+n2);
        
        vector<int> ans;
        
        int i=0,j=0;
        while(i<n1 and j<n2){
            if(nums1[i]>nums2[j]){
                ans.push_back(nums2[j++]);
            }
            else {
                ans.push_back(nums1[i++]);
            }
        }
        
        while(i<n1) ans.push_back(nums1[i++]);
        while(j<n2) ans.push_back(nums2[j++]);
        
        int m=ans.size()/2;
        
        if((k%2)==1) return double(ans[m]);
        return double((ans[m]+ans[m-1])/2.0);
        
    }
};