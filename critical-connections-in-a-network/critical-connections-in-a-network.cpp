class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int> adj[], vector<int>& vis, int low[], 
                int tin[], vector<vector<int>>& bridges){

        vis[node] = 1;
        low[node] = tin[node] = timer;
        timer++;

        for(auto adjNode: adj[node]){

            if(adjNode == parent)   continue;

            if(!vis[adjNode]){
                dfs(adjNode, node, adj, vis, low, tin, bridges);

                if(low[adjNode] < low[node])
                    low[node] = low[adjNode];

                if( low[adjNode] > tin[node] )  
                    bridges.push_back({node, adjNode});
            }
            else{
                 if(low[adjNode] < low[node])
                    low[node] = low[adjNode];
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        int tin[n];
        int low[n];

        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n,0);
        vector<vector<int>> bridges;

        
        dfs(0, -1, adj, vis, low, tin, bridges);
        
        return bridges;
    }
};