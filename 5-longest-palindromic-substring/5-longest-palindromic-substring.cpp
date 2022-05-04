class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n=s.length();
        int start=0,end=1;      //trackers for printing the string(min length will be 1)
        
        for(int i=1;i<n;i++){
            
            //for even length substring
            int l=i-1;
            int r=i;
            
            while(l>=0 and r<n and s[l]==s[r]){
                
                if(r-l+1>end){            //if we found a new greater palindromic string
                    start=l;              //set the trackers again
                    end=r-l+1;
                }
                l--;
                r++;
            }
            
            //for odd length substring
            l=i-1;
            r=i+1;
            
            while(l>=0 and r<n and s[l]==s[r]){
                
                if(r-l+1>end){
                    start=l;
                    end=r-l+1;
                }
                l--;
                r++;
            }
            
        }
        return s.substr(start,end);
    }
};