class Solution {
public:
    string reverseWords(string s)
    {
        int n=s.size();
        stack<string> st;
        
        for(int i=0;i<n;i++){
            string word;
            
            if(s[i]==' ') continue;
            
            while(i<n and s[i]!=' '){
                word+=s[i++];
            }
            
            st.push(word);
            word="";
        }
        
        string ans;
        while(!st.empty()){
            
            ans += st.top();
            st.pop();
            if(!st.empty()) ans += ' ';
        }
        return ans;
    }
};

