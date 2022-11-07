class Solution {
public:
    int maximum69Number (int num) {
        vector<int> arr;
        int ans=0;
        while(num!=0){
            int rem = num%10;
            arr.push_back(rem);
            num /= 10;
        }
    
        for(int i=arr.size()-1; i>=0; i--){
            if(arr[i]==6){
                arr[i]=9;
                break;
            }
        }
       
        for(int i=0;i<arr.size();i++){
            ans += arr[i] * pow(10,i);
        }
        return ans;
    }
};


//more efficient
// int maximum69Number (int num) {
        
//         string s = to_string(num);
        
//         /* You can change at the most one digit,
//            so traverse from left and change the first
//            encountered 6  to  9  (to increase th value of num) */
        
//         for(int i = 0 ; i < s.size() ; i++)
//         {
//             if(s[i] == '6')
//             {
//                 s[i] = '9';
//                 break;
//             }
//         }
        
//         return stoi(s);
//     }