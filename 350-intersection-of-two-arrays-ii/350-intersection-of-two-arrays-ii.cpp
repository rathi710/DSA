class Solution {
public:
    // using hashmap : tc:-o(n)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;
        map<int,int> m;
        for(auto it: nums2) m[it]++;
        for(auto i: nums1){
            if(m[i]){
                ans.push_back(i);
                m[i]--;
            }
        }
        return ans;
    }
};


//brute-force : o(n^2)
 // vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
 //        vector<int> ans;
 //        int n1 = nums1.size();
 //        int n2 = nums2.size();
 //        for(int i = 0; i < n1; i++) {
 //            for(int j = 0; j < n2; j++) {
 //                if(nums1[i] == nums2[j]){
 //                   ans.push_back(nums1[i]);
 //                    nums2[j] = -1; //so we dont choose the same numbe again
 //                    break;
 //                }
 //            }
 //        }
 //        return ans;
 //    }




//using 2-pointer approach - o(n)
// vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());   
//         vector<int>answer;
//         int i = 0, j = 0;
//         while(i < nums1.size() && j < nums2.size()) {
//             if(nums1[i] < nums2[j]){
//                 i++;
//             }
//             else if(nums1[i] > nums2[j]) {
//                 j++;
//             }
//             else {
//                 answer.push_back(nums1[i]);
//                 i++;
//                 j++;
//             }
//         }
//         return answer;
//     }