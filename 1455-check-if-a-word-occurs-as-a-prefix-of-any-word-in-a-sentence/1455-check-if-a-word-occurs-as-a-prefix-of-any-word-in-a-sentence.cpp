class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        int t = searchWord.size();
        string str;
        int c=0;
        
        for(int i=0;i<n;i++){
            str = "";
            c++;
            while(i < n && sentence[i] != ' '){
                str += sentence[i];
                i++;
            }
            
            if(str.size() >= t && str.substr(0,t) == searchWord) return c;
        }
        //to check the last word
        if(str.size() >= t && str.substr(0,t) == searchWord) return c;
        return -1;
    }
};