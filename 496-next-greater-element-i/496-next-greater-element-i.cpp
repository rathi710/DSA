class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int,int> map;           //we will be using map as next grtr array
        stack<int> st;
        
        for(int i=nums2.size()-1; i>=0; i--)
        {
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            
            //either the stack is empty now or we got our element
            int res = st.empty() ? -1 : st.top();
            map.insert({nums2[i],res});            //mapping it to later fetch it from the nums1
            st.push(nums2[i]);
        }
        
         //matching and putting value in output vector
        vector<int> ans;
        for(auto x: nums1){
            ans.push_back(map[x]);
        }
        
        return ans;
    }
};