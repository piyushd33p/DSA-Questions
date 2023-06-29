class DisjointSet{
    vector<int> parent, size;

    public:
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);

        for(int i =0  ; i < n ; i++){
            for(int j = 0 ; j<n;j++){
                if(isConnected[i][j] == 1){
                    ds.unionBySize(i,j);
                }
            }
        }
        int count = 0;

        for(int i = 0; i<n; i++){
            if(ds.findPar(i) == i)  count++;
        }

        return count;
    }
};