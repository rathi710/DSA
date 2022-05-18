class Solution {
public:
    string removeDuplicates(string s){
        
    stack<char> st;
	string ans="";
        
	for(auto curr:s)
    {
		if(st.empty()) st.push(curr);
		else if(st.top() == curr) st.pop();
		else st.push(curr);
	}

	while(!st.empty()) {
		ans += st.top();
		st.pop();
	}

	reverse(ans.begin(), ans.end());

	return ans;
    }
};