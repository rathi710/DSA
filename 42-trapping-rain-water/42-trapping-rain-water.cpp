class Solution {
public:
    // Solution Using Prefix Sum :: Time : O(3*N) :: Aux_Space : O(2*N)
    int trap(vector<int>& height) {

        int n = height.size();
        int res = 0;
        int lmax[n], rmax[n];

        //left  prefix
        lmax[0] = height[0];
        for(int i=1;i<n;i++)
            lmax[i] = max(height[i],lmax[i-1]);

        //right prefix
        rmax[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--)
            rmax[i] = max(height[i],rmax[i+1]);

         //adding trapped water   
        for(int i=0;i<n;i++){
            res += min(lmax[i],rmax[i]) - height[i];
        }

        return res;
    }
};




// Efficient Solution Using Two-Pointers :: Time : O(N) :: Aux_Space : O(1)

//     int trap(vector<int>& height) {

//         int n = height.size();
//         int low = 0,high = n-1;
//         int lmax = 0,rmax = 0,res =0;

//         while(low<=high){

//             if(height[low] <= height[high]){

//                 if(height[low] >= lmax){
//                     lmax = height[low];
//                 }else{
//                     res += lmax-height[low];
//                 }
//                 low++;

//             }else{

//                 if(height[high] >= rmax){
//                     rmax = height[high];
//                 }else{
//                     res += rmax-height[high];
//                 }
//                 high--;
//             } 
//         }
//         return res;

//     }