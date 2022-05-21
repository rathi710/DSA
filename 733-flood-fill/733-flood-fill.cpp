class Solution {
public:
    
    bool isValid(int sr,int sc,int r,int c,int color,vector<vector<int>> &image)
    {
        if(sr>=0 && sr<r && sc>=0 && sc<c && image[sr][sc]==color){
            return true;
        }
        return false;
    }
    
    void solve(int sr,int sc,int r,int c,int color,int newcolor,vector<vector<int>>& image)
    {
        image[sr][sc] = newcolor;
        
        if(isValid(sr+1,sc,r,c,color,image))
            solve(sr+1,sc,r,c,color,newcolor,image);
        
         if(isValid(sr-1,sc,r,c,color,image))
            solve(sr-1,sc,r,c,color,newcolor,image);
        
         if(isValid(sr,sc+1,r,c,color,image))
            solve(sr,sc+1,r,c,color,newcolor,image);
        
         if(isValid(sr,sc-1,r,c,color,image))
            solve(sr,sc-1,r,c,color,newcolor,image);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int r = image.size();
        int c = image[0].size();
        
        int color = image[sr][sc];
        
        if(color == newColor) return image;
        
        solve(sr,sc,r,c,color,newColor,image);
        
        return image;
    }
};