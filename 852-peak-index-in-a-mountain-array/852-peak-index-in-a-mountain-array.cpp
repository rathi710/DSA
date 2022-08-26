class Solution {
public:
   int peakIndexInMountainArray(vector<int>& a) {
        int n = a.size();
        
        //Peak exists somewhere in between start and end
        int start = 1, end = n-2;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            
            if(a[mid] > a[mid-1] && a[mid] > a[mid+1]) return mid;
            
            else if(a[mid-1] > a[mid]) 
                end = mid-1;
            else 
                start = mid+1;
        }
        return -1;
    }
};

//binary search varient