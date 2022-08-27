class Solution {
public:
    //binary search
    bool isPerfectSquare(int num) {
         long long  left = 1, right = num;
        
        while (left <= right) 
        {
            long long mid = (left + right) / 2;
            if (mid * mid == num) 
			return true; // check if mid is perfect square
            if (mid * mid < num) 
			{ // mid is small -> go right to increase mid
                left = mid + 1;
            }
			else {
                right = mid - 1; // mid is large -> to left to decrease mid
            }
        }
        return false;
    }
};