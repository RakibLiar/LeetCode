class Solution {
public:
    bool isRowValid(vector<char> &row) {
        vector<bool> v(10, false);
        for(int i=0; i<9; i++) {
            if(row[i] != '.' && v[row[i]-'0'])
                return false;
            if(row[i] != '.')
                v[row[i]-'0'] = true;
        }
        return true;
    }
    bool isColValid(vector<vector<char>> &board, int c) {
        vector<bool> v(10, false);
        for(int i=0; i<9; i++) {
            if(board[i][c] != '.' && v[board[i][c]-'0'])
                return false;
            if(board[i][c] != '.')
                v[board[i][c]-'0'] = true;
        }
        return true;
    }
    bool isSquareValid(vector<vector<char>> &board, int n) {
        int r = 3*(n/9), c = n%9;
        vector<bool> v(10, false);
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[r+i][c+j] != '.' && v[board[r+i][c+j]-'0'])
                    return false;
                if(board[r+i][c+j] != '.')
                    v[board[r+i][c+j]-'0'] = true;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            if(!isRowValid(board[i])) {
                return false;
            }
            if(!isColValid(board, i)) {
                return false;
            }
            if(!isSquareValid(board, 3*i)) {
                return false;
            }
        }
        return true;
    }
};