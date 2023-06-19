class Solution {
private:
    bool dfs(int node, vector<int> &vis, vector<int>& pathVis, vector<vector<int>>& graph, vector<int>& check){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto adjNode: graph[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode, vis, pathVis, graph, check) == 1)   return true;
            }
            else if(pathVis[adjNode] == 1)  return true;
        }

        pathVis[node] = 0;
        check[node] = 1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> pathVis(n, -1);
        vector<int> check(n,0);

        for(int i = 0 ; i  < n ; i++){
            if(!vis[i]){
                dfs(i, vis, pathVis, graph, check);
            }
        }

        vector<int> safeNodes;
        for(int i = 0  ; i <n ;i++){
            if(check[i] == 1)   safeNodes.push_back(i);
        }
        return safeNodes;
    }
};