class Solution {
public:
    vector<vector<int>> dp;
    bool check(int x, int y, vector<vector<char>> &board) {
        return 0<=x and x<board.size() and 0<=y and y<board[0].size();
    }
    
    void dfs(int x, int y, vector<vector<char>> &board) {
        if(!check(x, y, board) || board[x][y] != 'O')
            return;
        board[x][y] = '#';
        vector<int> dir {0,1,0,-1,0};
        for(int i=0; i<dir.size()-1; i++) {
            dfs(x+dir[i], y+dir[i+1], board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
        for(int i=0; i<row; i++) {
            if(board[i][0] == 'O')
                dfs(i, 0, board);
            if(board[i][col-1] == 'O')
                dfs(i, col-1, board);
        }
        for(int i=0; i<col; i++) {
            if(board[0][i] == 'O')
                dfs(0, i, board);
            if(board[row-1][i] == 'O')
                dfs(row-1, i, board);
        }
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};