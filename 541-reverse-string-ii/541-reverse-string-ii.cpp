class Solution {
public:
    string reverseStr(string s, int k) 
    {
        for(int i=0;i<=s.size();i+=2*k)
        {
            //this will reverse from index i to i+k and next after one iteration i                 //increments by i+2*k ignoring next k elements
            if(i+k<=s.size()) reverse(s.begin()+i,s.begin()+i+k); 
            
             //this reverses the last few elemnts which are less than k
            else reverse(s.begin()+i,s.end());
        }
        return s;
    }
};