class Solution {
public:
    bool isValid(string x) 
    {
        stack<char> st;
        char a;
        int n = x.size();
        
        for(int i=0;i<n;i++){         //traversing the string
            
            if(x[i]=='(' or x[i]=='{' or x[i]=='['){
                st.push(x[i]);
                continue;
            }
            else if(st.empty()) return false;        //if closing bracket comes at first 
            else{
                switch(x[i]){
                    case ')':
                    a = st.top();
                    st.pop();
                    if(a == '{' or a == '[') return false;
                    break;
                    
                    case '}':
                    a = st.top();
                    st.pop();
                    if(a == '(' or a == '[') return false;
                    break;
                    
                    case ']':
                    a = st.top();
                    st.pop();
                    if(a == '{' or a == '(') return false;
                    break;
                }
            }
            
        }
        return st.empty();
    }
};