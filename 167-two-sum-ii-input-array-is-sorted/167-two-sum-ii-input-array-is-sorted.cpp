class Solution {
public:
    //using Binary Search
    int search(vector<int>& arr, int i, int key) 
    {
        int l=i+1,mid,h=arr.size()-1;
        while(l<=h)
        {
            mid = l+(h-l)/2;
            if(key == arr[mid])
                return mid;
            else if(key < arr[mid])
                h=mid-1;
            else
                l=mid+1;
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> ans;
        for(int i=0; i<n ;i++){
            if(search(numbers, i, target - numbers[i]) != -1)
            {
                ans.push_back(i+1);
                ans.push_back(search(numbers,i,target-numbers[i])+1);
            }
        }
        return ans;
    }
};


// using map 
// vector<int> twoSum(vector<int>& arr, int t) {
//         unordered_map<int,int> mp;
//         vector<int>ans;
//         for(int i=0;i<arr.size();i++)
//         {
//             if(mp.count(t-arr[i]))
//             {
//                 ans.push_back(mp[t-arr[i]]+1);
//                 ans.push_back(i+1);
//             }
//             else
//                 mp[arr[i]]=i;
//         }
//     return ans;   

//also can use 2-pointer,brute-force