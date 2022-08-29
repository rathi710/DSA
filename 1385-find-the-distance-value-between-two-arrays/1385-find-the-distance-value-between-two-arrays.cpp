class Solution {
public:
    
    // The binary-search works as we keep on getting close to the num so if there's a case such that abs(num - arr[j]) <= d we will reach it in log(arr2.size()).
    
    bool isValid(vector<int> arr, int target, int d){
        int start = 0, end = arr.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(abs(arr[mid] - target) <= d) return false;
            else if(target > arr[mid]) start = mid+1;
            else end = mid-1;
        }
        return true;
    }
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) 
    {
        int c=0;
        sort(arr2.begin(),arr2.end());
        for(auto num: arr1){
            if(isValid(arr2,num,d)){
                c++;
            }
        }
        return c;
    }
};



//Brute-Force -> O(n^2) tc
 // int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d)  {
 //        int c=0;
 //        for(int i=0; i<arr1.size(); i++){
 //            int flag=1;
 //            for(int j=0; j<arr2.size(); j++){
 //                if(abs(arr1[i]-arr2[j]) <= d) flag = 0;
 //            }
 //            if(flag) c++;
 //        }
 //        return c;
 //    }