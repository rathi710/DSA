class Solution {
public:
    //Binary search : logn : IMP
    int arrangeCoins(int n) 
    {
       long low =0, high = n, tmp;
        
       while (low <= high) {
            long long mid = low + (high - low) / 2;
			long long cursum = mid * (mid + 1) / 2;
           
            if (cursum == n) return mid;    //mid no of stairs can be filled
            
            if (cursum <= n) low = mid + 1;  //move forward, more stairs can be filled
            else high = mid - 1;
        }
        return low-1;
    }
};

//Brute force : O(n) : Math
// int arrangeCoins(int n) {
//         int i=1;
//         while(i<=n){
//             n=n-i;
//             i++;
//         }
//         return i-1;
//     }