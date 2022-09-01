class Solution {
public:
    //Binary search : good ques on bs
    int findKthPositive(vector<int>& arr, int k) 
    {
        int low =0, high =arr.size()-1;
	    while(low<=high){     
            int mid= low+(high-low)/2;
            int missing= arr[mid]-(mid+1);

            if(missing < k)
                low = mid + 1;
            else
                high = mid - 1;
	    }
        
	    return low+k;
    }
};

//brute force : using set
// int findKthPositive(vector<int>& arr, int k) {
//         set<int> s;
//         for(auto i: arr) s.insert(i);
//         for(int i=1; i<10001; i++){
//             if(s.find(i) == s.end()) k--;
//             if(k == 0) return i;
//         }
//         return -1;
//     }