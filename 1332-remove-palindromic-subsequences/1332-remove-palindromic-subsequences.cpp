class Solution {
public:
    bool isPalindrome(string s)
    {
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++; r--;
        }
        return true;
    }
    
    int removePalindromeSub(string s)
    {
        //there are only 3 cases possible -: 0,1 & 2 
        if(s.empty()) return 0;
        
        else if(isPalindrome(s)){
            return 1;
        }
        return 2;
    }
};