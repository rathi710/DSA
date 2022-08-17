class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> s;  
        for(auto it: words){
            string str="";
            for(auto ch: it){
                str += codes[ch-97]; //to access the indexes 0,1,2... from the vector -codes
            }
            s.insert(str);
        }   
      return s.size();  
    }
};