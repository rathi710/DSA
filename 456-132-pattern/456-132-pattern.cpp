class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        stack<int> st;
        int n=nums.size();
        int thirdElement = INT_MIN;
        
        for(int i=n-1; i>=0; i--)
        {
            if(nums[i] < thirdElement) return true;
            while(!st.empty() && nums[i] > st.top()){
                thirdElement = st.top();
                st.pop();
            }
            
            st.push(nums[i]);
        }
        return false;
    }
};

//sol 1 : brute 
// Time Complexity :- BigO(N^3)
// Space Complexity :- BigO(1)

// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 for(int k=j+1;k<n;k++)
//                 {
//                     if(nums[k]<nums[j] && nums[k]>nums[i])return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

// 2nd solution : better

// Time Complexity :- BigO(N^2)
// Space Complexity :- BigO(1)

// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         int n=nums.size();
//         int m=nums[0];
//         for(int j=0;j<n;j++)
//         {
//             for(int k=j+1;k<n;k++)
//             {
//                 if(nums[k]>m && nums[j]>nums[k])return true;
//                 m=min(m,nums[j]);
//             }
//         }
//         return false;
//     }
// };


// sol 3 : optimal

// .firstly take a stack st.
// .than we add a new number
// firstly we pop out all the number that are small that number
// in this way last elemnt pop than become s3
// . we find maximum s3(recently poped number)

// Time Complexity :- BigO(N)
// Space Complexity :- BigO(N)
// DONE ABOVE