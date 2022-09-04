class Solution {
public:
    //Binary Search : decision in whether to go bottom or left encountering either a +ve/-ve no. 
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        //starting with the right  most upper corner and start finding 
        int i = 0, j = m-1;
        
        //if the element is negative then we have to  count all the vertical element in that             //point and move to next column.
        while(i < n && j >=0){
            if(grid[i][j] < 0){
                count += n-i;
                j -= 1;
            }
            //if it's positve then we know that all element in that vertical part is negative so             //we move to next row
            else 
                i += 1;
        }
        return count;
    }
};




//Alterantive way of using Binary Search: - 

// int countNegativesHelper(vector<int> arr)
//     {
//         int count=0;
//         int low=0;
//         int high=arr.size()-1;
    
//         while(low<=high)
//         {
//             mid=low+(high-low)/2;
//             if(arr[mid]<0){
//                 count=count+high-mid+1;    
//                 // discard everything after high which is negative
//                 high=mid-1;            
//             }
//             else{
//                  // discard everything before mid which is non-negative
//                  low=mid+1;               
//             }
//         }
//         return count;
//     }

//     int countNegatives(vector<vector<int>>& grid) {
//          int count = 0;
//         for (int i=0; i<grid.size(); i++) 
//         {
//             count += countNegativesHelper(grid[i]);
//         }
//         return count;
//     }