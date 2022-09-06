class Solution {
public:
    //2-pointer approach
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int maxi=0;
        
        int i=0,j=0;
        while(i < n1 && j < n2){
            if(nums1[i] <= nums2[j]){
                maxi = max(maxi,j-i);
                j++;
            }
            else i++;
        }
        return maxi;
    }
};



//using Binary-search :-
//  int maxDistance(vector<int>& nums1, vector<int>& nums2) {
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         int maxi=0;
        
//         for(int i=0; i<n1; i++)
//         {
//             int low = 0, high = n2-1;
            
//             while(low <= high){
//                 int mid = low + (high-low)/2;
                
//                 if(nums1[i] <= nums2[mid]){
//                     maxi = max(maxi,mid-i);
//                     low = mid+1;
//                 }
//                 else high = mid-1;
                
//             }
//         }
//         return maxi;
//     }




 //brute - force
 // int maxDistance(vector<int>& nums1, vector<int>& nums2) {
 //        int n1 = nums1.size();
 //        int n2 = nums2.size();
 //        int ans=0;
 //        for(int i=0; i<n1; i++){
 //            for(int j=0; j<n2; j++){
 //                if(i <= j && nums1[i] <= nums2[j])
 //                    ans = max(ans,j-i);
 //            }
 //        }
 //        return ans;
 //    }