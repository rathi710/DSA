class Solution {
public:
    //seive of eratosthenes
    int countPrimes(int n) {
        vector<bool> isPrime(n+1,true);
        //mark the 0 and 1 as false bcz they are not prime
        isPrime[0] = false;
        isPrime[1] = false;
        
        //loop to find the prime number and mark its multiples as false
        for(int i=2; i*i<=n; i++){
            for(int j=i*i; j<=n; j += i){
                isPrime[j] = false;
            }
        }
        
        //count the true values in the vector
        int c=0;
        for(int k=2; k<n; k++){
            if(isPrime[k]) c++;
        }
        return c;
    }
};