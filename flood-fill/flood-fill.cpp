class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans,
         int orgCol, int color, int delRow[], int delCol[]){

        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();

        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && 
                image[nrow][ncol] == orgCol && ans[nrow][ncol] != color){

                    dfs(nrow, ncol, image, ans, orgCol, color, delRow, delCol );
                }
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orgCol = image[sr][sc];

        vector<vector<int>> ans = image;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        dfs(sr, sc, image, ans, orgCol, color, delRow, delCol);
        return ans;
    }
};