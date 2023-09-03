class Solution {
private:
    bool isSafeSpot(vector<string>& board, int row, int col, int n){
        int orgRow = row, orgCol = col;

        while(row >= 0 && col >= 0){
            if(board[row--][col--] == 'Q')  return 0;
        }

        row = orgRow;
        col = orgCol;

        while(col >=0){
            if(board[row][col--] == 'Q')  return 0;
        }

        col = orgCol;

        while(row < n && col >=0){
            if(board[row++][col--] == 'Q')     return 0;
        }
        return 1;
    }

    void placeQueen(vector<vector<string>>& ans, vector<string>& board, int n, int col){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int i = 0; i < n; i++){
            int row = i;
            if(isSafeSpot(board, row, col, n)){
                board[row][col] = 'Q';
                placeQueen(ans, board, n, col+1);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);

        string s(n,'.');

        for(int i = 0; i <n; i++)   board[i] = s;

        placeQueen(ans, board, n, 0);

        return ans;
    }
};