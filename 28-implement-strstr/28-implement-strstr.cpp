class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int n1=haystack.size();
        int n2=needle.size();
        
        if(needle.empty()) return -1;        //if needle string is empty
        
        int i=0,j=0;
        
        while(i<n1 and j<n2){
            
            if(haystack[i]==needle[j]){
                i++;                         //when there is a match then increase both the pointers
                j++;
                if(j==n2) return i-n2;       //if the whole pattern has been matched then return
            }
            
            else {
                i=i-j+1;              //go back again plus one,so that no pattern could be missed(IMP)
                j=0;                  //start checking from pattern's beginning
            }
            
        }
        return -1;
    }
};


//two-pointer variation
