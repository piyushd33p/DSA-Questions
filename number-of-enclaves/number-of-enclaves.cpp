class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>> &vis){
        vis[row][col] = 1;

        queue<pair<int, int>> q;
        q.push({row, col});

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i<4; i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if(nrow >=0 && nrow < n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m,0));

        for(int j = 0; j< m ; j++){
            if(grid[0][j] == 1 && !vis[0][j]){
                bfs(0, j, grid, vis);
            }
            if(grid[n-1][j] == 1 && !vis[n-1][j]){
                bfs(n-1, j, grid, vis);
            }
        }

        for(int i = 0 ; i<n; i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                bfs(i, 0, grid, vis);
            }
            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                bfs(i, m-1, grid, vis);
            }
        }

        int enclaves = 0;

        for(int i = 0 ; i<n; i++){
            for(int j = 0 ; j <m ;j++){
                if(!vis[i][j] && grid[i][j] == 1)   enclaves++;
            }
        }

        return enclaves;
        
    }
};