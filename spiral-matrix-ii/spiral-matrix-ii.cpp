class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        int sRow = 0, sCol = 0, eRow = n-1, eCol = n-1;

        int count = 1, size = n*n;

        while(count <= size){

            for(int i = sCol; i <= eCol; i++){
                if(count <= size){
                    mat[sRow][i] = count;
                    count++;
                }
            }
            sRow++;

            for(int i = sRow; i<= eRow; i++){
                if(count <= size){
                    mat[i][eCol] = count;
                    count++;
                }
            }
            eCol--;

            for(int i = eCol; i>= sCol; i--){
                if(count <= size){
                    mat[eRow][i] = count;
                    count++;
                }
            }
            eRow--;

            for(int i = eRow; i>=sRow; i--){
                if(count<=size){
                    mat[i][sCol] = count;
                    count++;
                }
            }
            sCol++;
        }
        return mat;
        
    }
};