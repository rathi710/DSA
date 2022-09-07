class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        long long int i=0, j = sqrt(c);
        
        while(i <= j)
        {
            if(i*i+j*j==c){
				return true;
			}
            else if(i*i+j*j>c){
                j--;
			}
            else{
                i++;
			}
        }
        return false;
    }
};


// 2-pointer
// binary search
