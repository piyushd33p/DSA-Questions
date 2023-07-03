class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> table;
        
        for(int row = 0; row < numRows; row++){
            table.push_back(vector<int>(row+1, 1));

            for(int col = 1; col < row; col++){
                table[row][col] = table[row-1][col-1] + table[row-1][col];
            }
        }
        return table;
    }
};