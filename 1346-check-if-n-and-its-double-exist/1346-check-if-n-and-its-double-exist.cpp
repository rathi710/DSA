class Solution {
public:
    //using binary search
    bool check(vector<int>& arr, int it){
        int target = 2*arr[it];
        int low = 0, high = arr.size()-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] == target && mid != it) return true;
            else if(arr[mid] > target) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
    
    bool checkIfExist(vector<int>& arr) 
    {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        for(int i=0; i<n; i++){
            if(check(arr,i)) return true;
        }
        return false;
    }
};




//using map
//  bool checkIfExist(vector<int>& arr) 
//     {
//         int n=arr.size();
//         unordered_map<int,int> m;
       
//         for(int i=0;i<n;i++){
//             if(m.count(2*arr[i]) or m.count(arr[i]/2) && arr[i]%2==0)
//                 return true;
//             else
//                 m[arr[i]]++;
                                                                      
//         }
//         return false;
//     }