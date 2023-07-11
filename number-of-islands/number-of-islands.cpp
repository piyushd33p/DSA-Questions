class Solution {
private:

    bool isValid(int row, int col, int n, int m){
        return row>=0 && row<n && col>=0 && col<m;
    }

    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        int delRow[]  = {-1,0,1,0};
        int delCol[]  = {0, -1, 0, 1};

        for(int i =0 ; i <4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(isValid(nrow, ncol, n, m) && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                dfs(nrow, ncol, vis, grid);
            }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        int island = 0;
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j < m; j++){
                if(!vis[i][j] && grid[i][j]== '1'){
                    island++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return island;
    }
};