class Solution {
public:
    bool check(vector<vector<char>>& board, int i, int j, char c){
        int row = i-i%3, col = j-j%3;
        for(int x=0;x<9;x++) if(board[x][j]==c) return false;
        for(int y=0;y<9;y++) if(board[i][y]==c) return false;
        // Each box
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                if(board[row+x][col+y] == c) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int i, int j) {
        // reached last row
        if (i == 9)
            return true;
        // reached last col then move to next row from col 0
        if (j == 9)
            return solve(board, i + 1, 0);
        if (board[i][j] != '.')
            return solve(board, i, j+1);

        for (char c = '1'; c <= '9'; c++) {
            // check if the char c can be filled there..
            if (check(board, i, j, c)) {
                board[i][j] = c;
                // after filling the char is the board is correct.
                if (solve(board, i, j + 1))
                    return true;
                // otherwise make it _
                board[i][j] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board, 0, 0); }
};