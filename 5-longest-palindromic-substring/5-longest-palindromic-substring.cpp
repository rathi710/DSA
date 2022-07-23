class Solution {
public:
    //using dp (variation of longest common substring)
    string longest_common_substring(string str1, string str2) 
    {   
        int s1 = str1.size(); int s2 = str2.size();
        int dp[s1+1][s2+1];
        string res ; int max = 0 ;

        for(int i=0; i<=s1; i++)
        {
            for(int j=0; j<=s2; j++)
            {   if(i==0 || j==0){ dp[i][j] = 0;}
             
                else if(str1[i-1] == str2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    
                    if(dp[i][j]>max)
                    {
                        string temp = str1.substr(i-dp[i][j], dp[i][j]) ;
                        
                        string revtemp = string(temp.rbegin(),temp.rend());
                        if(revtemp==temp)
                        {
                            max = dp[i][j] ;
                            res = temp ;
                        }
                    }
                }
                else
                { dp[i][j] = 0 ; }
            }
        }

        return res;
    }
    
    string longestPalindrome(string s)
    {
        string srev = string(s.rbegin(),s.rend());
        return longest_common_substring(s, srev); 
    }
};


// another method:-

// string longestPalindrome(string s) 
//     {
//         int n=s.length();
//         int start=0,end=1;      //trackers for printing the string(min length will be 1)
        
//         for(int i=1;i<n;i++){
            
//             //for even length substring
//             int l=i-1;
//             int r=i;
            
//             while(l>=0 and r<n and s[l]==s[r]){
                
//                 if(r-l+1>end){            //if we found a new greater palindromic string
//                     start=l;              //set the trackers again
//                     end=r-l+1;
//                 }
//                 l--;
//                 r++;
//             }
            
//             //for odd length substring
//             l=i-1;
//             r=i+1;
            
//             while(l>=0 and r<n and s[l]==s[r]){
                
//                 if(r-l+1>end){
//                     start=l;
//                     end=r-l+1;
//                 }
//                 l--;
//                 r++;
//             }
            
//         }
//         return s.substr(start,end);
//     }