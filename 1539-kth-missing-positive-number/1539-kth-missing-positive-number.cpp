class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        set<int> s;
        for(auto i: arr) s.insert(i);
        for(int i=1; i<10001; i++){
            if(s.find(i) == s.end()) k--;
            if(k == 0) return i;
        }
        return -1;
    }
};