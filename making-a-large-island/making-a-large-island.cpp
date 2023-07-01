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
private:
    bool isValid(int row, int col, int n){
        return row>=0 && row<n && col>=0 && col<n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        // STEP -1 Make the components using the disjoint sets
        for(int row = 0 ; row < n; row++){
            for(int col = 0 ; col<n; col++){

                if(grid[row][col] == 1){

                    int dr[] = {-1,0,1,0};
                    int dc[] = {0,-1,0,1};

                    for(int i = 0 ; i < 4; i++){
                        int nrow = row + dr[i];
                        int ncol = col + dc[i];

                        if(isValid(nrow, ncol, n) && grid[nrow][ncol] == 1){
                            int nodeNo = row*n + col;
                            int adjNodeNo = nrow * n + ncol;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
        }

        // STEP-2 Try all zeroes and check for components.size()

        int mx  = 0;
        for(int row = 0 ; row<n; row++){
            for(int col = 0 ; col < n ; col++){

                if(grid[row][col] == 0){
                    int dr[] = {-1,0,1,0};
                    int dc[] = {0,-1,0,1};
                    set<int> components;    

                    for(int i = 0 ; i< 4 ; i++){
                        int nrow = row + dr[i];
                        int ncol = col + dc[i];

                        if(isValid(nrow, ncol, n) && grid[nrow][ncol] == 1){
                            int node = nrow * n + ncol;
                            components.insert(ds.findPar(node));
                        }
                    }

                    int totalSize = 0;
                    for(auto it: components){
                        totalSize += ds.size[it];
                    }
                    mx = max(mx, totalSize +1);
                }
            }
        }

        // EDGE CASE - What if all the cells are 1 so you need to find the ultimate parent
        for(int cell = 0; cell <n*n; cell++){
            mx = max(mx, ds.size[ds.findPar(cell)]);
        }

        return mx;

    }
};
















