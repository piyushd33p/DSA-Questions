
class Solution {

private:
    void dfs(vector<int> adj[], vector<bool> &vis, int node){
        vis[node] = 1;

        for(auto i : adj[node]){
            if(!vis[i])  
                dfs(adj, vis, i);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> adj[n];

        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n ; j++){

                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n,0);

        int numProvince = 0;

        for(int i = 0 ; i < n; i++){
            if(!vis[i]){
                numProvince++;
                dfs( adj, vis, i);
            }
        }

        return numProvince;
    }
};