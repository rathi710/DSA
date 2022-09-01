// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    //binary search: very easy
    int firstBadVersion(int n) 
    {
        int l = 1 ,r = n;
        int ans=0;
        
        while(l <= r)
        {
            long long mid = l +(r-l)/2;
            bool tmp = isBadVersion(mid);
            if(tmp == true){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};