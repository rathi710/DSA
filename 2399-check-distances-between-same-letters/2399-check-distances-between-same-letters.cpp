class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) 
    {
       unordered_map<int, int> m;
        
        for(int i = 0;i < s.length(); i++)
        {
            if(m[s[i]]){
                if(distance[s[i] - 'a'] != (i - m[s[i]] )) return false;
            }
            else m[s[i]] = i+1;
            
        }
        return true;
    }
};

// distance is the number of elements between them.

// -> Iterate through string.
// -> If {
//    you see the element first time just keep in the map, so that If we get again we can   compute the distance.
// }
// else{
//      If we see second time.(first time already occured and stored the index value in map)

// -> Now just calcualte the number of elements between them and compare the value which is given in distance array
// -> (Present index - stored index in map).
// }