class Solution {
public:
    
    void rec(vector<char> &s, int l, int r){
        if(l >= r) return;
        swap(s[l++],s[r--]);
        rec(s,l,r);
    }
    
    void reverseString(vector<char>& s) {
        rec(s,0,s.size()-1);
    }
};