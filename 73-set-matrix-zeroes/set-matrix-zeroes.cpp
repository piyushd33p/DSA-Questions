class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<pair<int,int>> zero;

        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 0){
                    pair<int,int> p = make_pair(i , j);
                    zero.push_back(p);
                }
            }
        }

        for(auto it : zero){
            int ptr1 = 0, ptr2 = 0, zRow = it.first, zCol = it.second ;

            while(ptr1 < n){
                mat[ptr1][zCol] = 0;
                ptr1++;
            }

            while(ptr2 < m){
                mat[zRow][ptr2] = 0;
                ptr2++;
            }
        }
    }

};