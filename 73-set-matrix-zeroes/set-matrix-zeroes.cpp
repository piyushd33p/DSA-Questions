class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        
        int col0 = 1;
        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0; i< n; i++){
            for(int j = 0 ; j < m ; j++){
                if(j == 0 && mat[i][j] == 0){
                    col0 = 0;
                }
                else if(mat[i][j] == 0){
                    mat[0][j] = 0;
                    mat[i][0] = 0;
                }
                
            }
        }
        for(int i = n-1; i > 0; i--){
            for(int j = m-1; j >0; j--){
                if(mat[0][j] == 0 || mat[i][0]== 0)
                    mat[i][j] = 0;
            }
        }

        //for zerorow
        for(int i = m-1; i > 0 ; i--){
            if(mat[0][i] == 0 || mat[0][0] == 0){
                mat[0][i] = 0;
            }
        }

        //for zerocol
        for(int i = n-1; i>=0; i--){
            if(mat[i][0] == 0 || col0 == 0 ){
                mat[i][0] = 0;
            }
        }
    }
};