class Solution {
public:
    //without backtracking(simple recursion)
    void helper(vector<string>&ans, int n, int open, int close, string curr)
    {
        if(curr.size() == 2*n){      //or open=close=n
            ans.push_back(curr);
            return;
        }
        
        if(open<n) helper( ans, n, open+1, close, curr+'(' );
        if(close<open) helper( ans, n, open, close+1, curr+')' );
    }
    
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        helper(ans,n,0,0,"");
        return ans;
    }
};



//with backtracking
// void solve(int n, int openings , int closings , string temp, vector<string> &ans){
//         if(temp.size()==2*n){
//             ans.push_back(temp);
//             return ;
//         }
        
//         if(openings<n){
//              temp+='(';
//             solve(n,openings+1,closings,temp,ans);
//             temp.pop_back();
//         }
        
//         if(closings<openings){
//              temp+=')';
//             solve(n,openings,closings+1,temp,ans);
//             temp.pop_back();
//         }
//           return ;
//     }
//     vector<string> generateParenthesis(int n) {
//         vector<string> ans;
//         solve(n,0,0,"",ans);
//         return ans;
//     }



// bro in the first we are directly adding in the string , and each time the function will be called , an new copy of string temp will be made , which will indeed lead to more time complexity. and in the second we have used the normal backtracking method , and therefore a new copy of temp string will not be made , and therefore once we add a character in the string it will must be popped back ,so that we can look for future solutions , but in the 1st method a new copy of temp string will be made , each time , therefore no need to pop . everything else is same as you can see , only this is the slightest of difference .