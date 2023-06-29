class DisjointSet{

    public:

    vector<int> parent, size;
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0 ; i< n; i++){
            parent[i] = i;
        }
    }

    int findPar(int node){
        if(node == parent[node])    return node;

        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if(ulp_u == ulp_v)  return;
        else if(size[ulp_u]  < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int extraEdge = 0;

        for(auto it: connections){
            int u = it[0];
            int v = it[1];

            if(ds.findPar(u) == ds.findPar(v))  extraEdge++;
            else    ds.unionBySize(u,v);
        }

        int compo = 0;
        for(int i = 0; i< n ; i++)  if(ds.parent[i] == i)  compo++;

        int ans = compo - 1;

        if(extraEdge >= ans)    return ans;
        return -1;

    }
};