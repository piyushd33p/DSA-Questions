class Solution {
private:
    bool isValid(int row, int col, int n, int m){
        return row >=0 && row < n && col >=0 && col<m;
    }
    void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int sr, int sc, int color, int prevColor,
             int n, int m){
        ans[sr][sc] = color;

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};

        for(int i = 0; i< 4; i++){
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];

            if(isValid(nrow, ncol, n, m) && image[nrow][ncol] == prevColor && ans[nrow][ncol] != color){
                dfs(image, ans, nrow, ncol, color, prevColor, n, m);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> ans = image;
        
        dfs(image, ans, sr, sc, color, image[sr][sc], n, m);
        
        return ans;
    }
};