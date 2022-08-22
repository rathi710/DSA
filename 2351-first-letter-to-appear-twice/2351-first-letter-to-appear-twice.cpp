class Solution {
public:
    char repeatedCharacter(string s) 
    {
        unordered_map<char,int> m;
        for(auto it: s){
            
            if(m.count(it)==1) return it;
            
            m[it]++;
        }
        
        return -1;
    }
};