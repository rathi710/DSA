class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n=s.length();
        unordered_set<char> st;          //set to store occoured characte
        int maxlen=0;
        int left=0,right=0;            //two pointers to navigate
        
        while(right<n){
             
            if(st.find(s[right])==st.end()){            //if the char is not in the subset
                                                      
                st.insert(s[right]);                   //put it in the set
                maxlen = max(maxlen,right-left+1);    //find the max size
                right++;
            }
            
            else{                                   //if already there 
               st.erase(s[left]);                    //shrink the window from left 
               left++;                              //until the repeated char is not omitted from left
               
               
            }
        }
        
        return maxlen;
    }
};