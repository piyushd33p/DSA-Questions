class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];

        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
                // stop,node,prevWt
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});

        vector<int> dist(n,INT_MAX);
        dist[src] = 0;

        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int prevWt = q.front().second.second;

            q.pop();

            if(stop > k)    break;

            for(auto it: adj[node]){
                int adjNode = it.first;
                int wt = it.second;

                if(prevWt + wt < dist[adjNode] && stop <=k){
                    dist[adjNode] = prevWt + wt;
                    q.push({stop+1,{adjNode, dist[adjNode]}});
                }
            }
        }

        if(dist[dst] == INT_MAX)    return -1;
        return dist[dst];
    }
};