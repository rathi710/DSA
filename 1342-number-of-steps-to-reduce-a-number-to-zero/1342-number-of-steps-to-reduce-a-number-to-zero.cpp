class Solution {
public:
    //using recursion
    int helper(int n, int &steps){
        if(n == 0) return steps;
        
        if(n%2==0) return helper(n/2, ++steps);
        return helper(n-1, ++steps);
    }
    
    int numberOfSteps(int num) {
        int steps=0;
        return helper(num,steps);
    }
};

//brute-force
 // int numberOfSteps(int num) 
 //    {
 //        int steps=0;
 //        while(num!=0){
 //            if(num%2==0){
 //                num /= 2;
 //                steps++;
 //            }
 //            else{
 //                num--;
 //                steps++;
 //            }
 //        }
 //        return steps;
 //    }