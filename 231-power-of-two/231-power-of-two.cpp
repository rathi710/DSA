class Solution {
public:
    
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        if(n==1) return true;
        return n%2 == 0 and isPowerOfTwo(n/2);
    }
};

//recursive- above
// If a number is power of two, it can be recursively divided by 2 till it becomes 1
// If the start number is 0 or if any intermediate number is not divisible by 2, we return false


//iteration
// bool isPowerOfTwo(int n) {
//         if(n == 0) return 0;
//         while(n % 2 == 0) 
//             n /= 2;
//         return n == 1;
//     }