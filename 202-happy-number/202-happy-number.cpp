class Solution {
public:
    bool isHappy(int n) 
    {
        set<int> set;
        while(1){
            int sum=0;
            while(n){
                int t = n%10;
                sum += t*t;
                n = n/10;
            }
            n = sum;
            if(n == 1) return true;
            else if(set.count(n) == 1) return false;    //so we dont get into the loop
            
            set.insert(n);
        }
        return false;
    }
};