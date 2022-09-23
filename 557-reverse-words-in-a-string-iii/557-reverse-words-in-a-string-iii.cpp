class Solution {
public:
    string reverseWords(string s) 
    {
        string result,word;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                word+=s[i];
            }
            else{
                reverse(word.begin(),word.end());
                result+=(word);
                result+=" ";
                word.clear();
            }
        }
        reverse(word.begin(),word.end());
        result+=word;
        return result;
    }
};

//2-pointer approach
// string reverseWords(string s) {
//         int i = 0;
//         for (int j = 0; j < s.size(); ++j)
//         {
//             if (s[j] == ' ') {
//                 reverse(s.begin() + i, s.begin() + j);
//                 i = j + 1;
//             }
//         }
//         reverse(s.begin() + i, s.end());
//         return s;
//     }