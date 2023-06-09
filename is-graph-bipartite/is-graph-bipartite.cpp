class Solution {
private:
    bool checkBipartite(int start, vector<vector<int>>& graph, vector<int>& color){
        color[start] = 0;

        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto adjNode : graph[node]){
                if(color[adjNode] == -1){
                    color[adjNode] = !color[node];
                    q.push(adjNode);
                }

                else if(color[adjNode] == color[node])      return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n,-1);

        for(int i = 0 ; i < n ; i++){
            if(color[i] == -1){
                if(checkBipartite(i, graph, color) == false)    return false;
            }
        }
        return true;    
    }
};