class Solution {
private:
    int findPaths(int m, int n, int i, int j, vector<vector<int>>& dp){
        if( i== m-1 && j == n-1){
            
            return 1;
        }
        if(i >= m || j>=n)  return 0;

        if(dp[i][j] != 0)   return dp[i][j];

         int down =   findPaths(m, n, i+1, j,dp);
        
        
          int up =   findPaths(m, n, i ,j+1,dp);

          return dp[i][j] = up+down;
        
    }
public:
    int uniquePaths(int m, int n) {
        vector<int> count(1,0);
        vector<vector<int>> dp(m, vector<int>(n,0));

        return findPaths(m, n, 0,0, dp);
        
    }
};