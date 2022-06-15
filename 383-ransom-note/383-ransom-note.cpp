class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        
        map<char,int> m;
       for(auto x: magazine){
           m[x]++;
       }
        
        for(auto ch: ransomNote){
            if(m[ch]>0) m[ch]--;
            else return false;
        }
        return true;
    }
};