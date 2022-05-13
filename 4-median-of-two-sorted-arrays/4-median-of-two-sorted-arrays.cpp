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



//more optimised merge

// int n1 = nums1.size(), n2 = nums2.size(), k = 0, l1 = 0, l2 = 0, n = n1 + n2;
// 	int num[n / 2 + 1];
// 	while (l1 < n1 && l2 < n2 && k <= n / 2)
// 	{
// 		if (nums1[l1] < nums2[l2])
// 			num[k++] = nums1[l1++];
// 		else
// 			num[k++] = nums2[l2++];
// 	}
// 	while (l1 < n1 && k <= n / 2)
// 		num[k++] = nums1[l1++];
// 	while (l2 < n2 && k <= n / 2)
// 		num[k++] = nums2[l2++];

// 	if (n % 2 == 0)
// 		return double(num[n / 2] + num[n / 2 - 1]) / 2;
// 	return double(num[n / 2]);