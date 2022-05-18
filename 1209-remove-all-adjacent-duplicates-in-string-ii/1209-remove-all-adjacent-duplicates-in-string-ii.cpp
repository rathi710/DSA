class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        vector<pair<char,int>> str;          //using vector as kind of stack
        
        for(auto x: s){
            
            //if there is no ele or the new ele & last ele is not equal
            if(str.size()==0 || str.back().first != x)
            {
                str.push_back({x,1});
            }
            else{
                str.back().second++;         //if incoming is equal,then increase the count
            }
            
            if(str.back().second == k){
                str.pop_back();
            }
        }
        
        string ans;
        for(auto t: str){
            ans.append(t.second,t.first);      //append(count of ele, ele)
            
        }
        return ans;
    }
};