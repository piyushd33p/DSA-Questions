class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pVis(n, vector<int>(m,0));
        vector<vector<int>> aVis(n, vector<int>(m,0));
        
        queue<pair<int,int>> qPac;
        queue<pair<int,int>> qAtl;

        for(int i = 0 ; i < n; i++){
            qPac.push({i,0});
            pVis[i][0] = 1;

            qAtl.push({i, m-1});
            aVis[i][m-1] = 1;
        }

        for(int j =0 ; j < m; j++){
            qPac.push({0,j});
            pVis[0][j] = 1;

            qAtl.push({n-1, j});
            aVis[n-1][j] = 1;
        }

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};


        while(!qPac.empty()){
            int r = qPac.front().first;
            int c = qPac.front().second;

            qPac.pop();

            for(int i = 0 ; i<4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !pVis[nrow][ncol] && 
                    heights[nrow][ncol] >= heights[r][c]){
                        pVis[nrow][ncol] =1;
                        qPac.push({nrow, ncol});
                }
            }

        }
        while(!qAtl.empty()){
            int r = qAtl.front().first;
            int c = qAtl.front().second;

            qAtl.pop();

            for(int i = 0 ; i<4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !aVis[nrow][ncol] && 
                    heights[nrow][ncol] >= heights[r][c]){
                        aVis[nrow][ncol] =1;
                        qAtl.push({nrow, ncol});
                }
            }

        }

        vector<vector<int>> ans;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m; j++){
                if(aVis[i][j] == 1 && pVis[i][j] == 1)  ans.push_back({i,j});
            }
        }
        return ans;
    }
};