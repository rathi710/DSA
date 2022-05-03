class Solution {
public:
    
    int minlen(vector<string> &strs)
    {
        int len=strs[0].size();
        
        for(int i=1;i<strs.size();i++){
            
            if(strs[i].size()<len){
                len = strs[i].size();
            }
        }
        return len;
    }
    
    string longestCommonPrefix(vector<string>& strs) 
    {
        int n=strs.size();
        int min = minlen(strs);       
        string ans;
        
        for(int i=0;i<min;i++){
            
            for(int j=1;j<n;j++){
                
                if(strs[0][i]!=strs[j][i]){
                    return ans;
                }
            }
            
            ans += strs[0][i];
        }
        return ans;
    }
};


//-----------------------------------------------------------------------------------------------
//by sorting-> O(nlogn)=tc

 // string longestCommonPrefix(vector<string>& strs) {
 //        int n = strs.size();
 //        string ans = ""; 
 //        sort(strs.begin(), strs.end());
 //        for(int i = 0; i< strs[0].size(); i++){
 //            if(strs[0][i] == strs[n-1][i]){
 //                ans += strs[0][i];
 //            }
 //            else
 //                break;
 //        }
 //        return ans;
 //    }

//------------------------------------------------------------------------------------------------
//sorting only->

// string longestCommonPrefix(vector<string>& strs) {
        
//         if(strs.size() == 0) return "";
        
//         sort(strs.begin(),strs.end());
//         string ans = "";
//         string firstString = strs[0];
//         string lastString = strs[strs.size()-1];
//         int i = 0;
        
//         while(firstString[i] == lastString[i]){
//             ans += firstString[i];
//             i++;
//         }
//         return ans;
//     }





