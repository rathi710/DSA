class Solution {
public:
int largestRectangleArea(vector<int>& heights)
{
        int n = heights.size() ; 
        vector<int> left(n), right(n); 
        stack<int> s ; 
    
        //for left smaller element
        for(int i = 0 ; i < n ; i++) {
            while(!s.empty() && heights[i] <= heights[s.top()])
                s.pop() ;
            
            if(s.empty())  left[i] = 0 ;    //minimum element
            else  left[i] = s.top() + 1 ;
            s.push(i) ; 
        }
    
        while(!s.empty())   s.pop() ; 
    
        //for right smaller element
        for(int i = n - 1 ; i >= 0 ; i--) {
            while(!s.empty() && heights[i] <= heights[s.top()]) 
                s.pop() ;
            
            if(s.empty())  right[i] = n - 1 ; //minimum element
            else   right[i] = s.top() - 1 ;
            s.push(i) ; 
        }
    
        int max_area = 0 ; 
        for(int i = 0 ; i < n ; i++) {
            max_area = max(max_area , heights[i] * (right[i] - left[i] + 1)) ;
        }
        return max_area ;
    }
};

//  Using left_smaller and right_smaller O(N)(2 pass)-above
// we use two arrays left and right which store the next smaller element to the left and right respectively.
// then for every index we calculate area as heights[i] * (right[i] - left[i] + 1)