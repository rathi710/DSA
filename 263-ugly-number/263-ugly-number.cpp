class Solution {
public:
    bool isUgly(int n) {
        //0 is limited to 2,3,5 coz it has nothing 
        if(n == 0) return false;
        
        while(n%2 == 0) n /= 2;
        while(n%3 == 0) n /= 3;
        while(n%5 == 0) n /= 5;
        
        return n == 1;
    }
};