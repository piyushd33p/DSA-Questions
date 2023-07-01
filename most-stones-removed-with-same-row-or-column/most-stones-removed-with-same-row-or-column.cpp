class DisjointSet{
    public:
    vector<int> size, parent;

    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i =0 ; i< n; i++)   parent[i] = i;
    }

    int findPar(int node){
        if(node == parent[node])    return node;

        return parent[node] = findPar(parent[node]); 
    }

    void unionBySize(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if(ulp_u == ulp_v)  return;
        else if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += ulp_v;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0, maxCol = 0;

        for(auto it: stones){
            maxRow  = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol +2);
        set<int> compos;

        for(auto it:stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow +1;

            ds.unionBySize(nodeRow, nodeCol);
            compos.insert(nodeRow);
            compos.insert(nodeCol);
        }

        int countCompo = 0;

        for(auto it: compos){
            if(ds.findPar(it) == it)    countCompo++;
        }

        return n - countCompo;
        
    }
};





