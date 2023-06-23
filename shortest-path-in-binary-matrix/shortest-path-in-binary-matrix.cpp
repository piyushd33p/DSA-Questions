class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1)     return -1;
        if(grid[n-1][n-1] != 0) return -1;


        queue<pair<int, pair<int,int>>> q;
        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));

        q.push({1,{0,0}});
        dist[0][0] = 1;

        int drow[] = {-1, 0, +1, 0, 1, -1, -1, 1};
        int dcol[] = {0, 1, 0, -1, 1, 1, -1, -1}; 

        while(!q.empty()){
            int prevWt = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;

            q.pop();

            if(r == n-1 && c == n-1) return prevWt;

            for(int i = 0; i < 8; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                if( nrow >=0 && nrow < n && ncol >=0 && ncol < m && grid[nrow][ncol] == 0 
                    && prevWt + 1 < dist[nrow][ncol] ){
                    dist[nrow][ncol] = prevWt + 1;
                    q.push({dist[nrow][ncol], {nrow, ncol}});
                }

            }
        }

        return -1;
        
    }
};