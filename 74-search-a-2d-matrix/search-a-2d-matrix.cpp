class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowCount= matrix.size();
        int colCount = matrix[0].size();

        int row = 0, col = colCount-1;

        while(row < rowCount && col >=0){
            if(matrix[row][col] == target)  return 1;
            else if(matrix[row][col] > target)  col--;
            else    row++;
        }
        return 0;
    }
};