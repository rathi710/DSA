class Solution {
public:
    //using hashmap with priority queue
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> ans;
        
        for(auto it: nums){
            m[it]++;
        }
        
        for(auto it: m){
            pq.push({it.second,it.first});
            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()){
            pair<int,int> t = pq.top();
            pq.pop();
            ans.push_back(t.second);
        }
        
        return ans;
    }
};


//without using priority queue:-

    // bool static comp(pair<int,int> a, pair<int,int> b){
    //     return a.second < b.second;
    // }
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     map<int,int> mp;
    //     vector<int> ans;
    //     vector<pair<int,int>> v;
    //     for(auto&it:nums){
    //         mp[it]++;
    //     }
    //     for(auto it:mp) v.push_back(it);

    //     sort(v.begin(),v.end(),comp);
    //     for(int i=v.size()-1;i>=0;i--){
    //         if(k == 0) break;
    //         ans.push_back(v[i].first);
    //         k--;
    //     }
    //     return ans;
    // }