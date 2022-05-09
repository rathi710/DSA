class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> ans;
        int n= matrix[0].size();
        int m= matrix.size();
        
        int top=0;
        int down=m-1;
        int left=0;
        int right=n-1;
        
        int count=0;
        
        while(top<=down && left<=right){
            
            if(count==0){
                for(int i=left; i<=right; i++)
                    ans.push_back(matrix[top][i]);
                top++; 
                count++;
            }
            
            else if(count==1){
                for(int i=top; i<=down; i++)
                    ans.push_back(matrix[i][right]);
                right--; 
                count++;
            }
            
            else if(count==2){
                for(int i=right; i>=left; i--)
                    ans.push_back(matrix[down][i]);
                down--; 
                count++;
            }
            
            else if(count==3){
                for(int i=down; i>=top; i--)
                    ans.push_back(matrix[i][left]);
                left++; 
                count=0;
            }
        }
        
        return ans;
    }
};