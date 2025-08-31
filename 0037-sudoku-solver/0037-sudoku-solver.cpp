class Solution {
public:
    int N = 9;
    bool isValid(vector<vector<char>>& grid, int row, int col, int num)
    {
        for(int i=0; i<N; i++)
        {
            if(grid[row][i] == num + '0')
                return false;
        }
        
        for(int i=0; i<N; i++)
        {
            if(grid[i][col] == num + '0')
                return false;
        }
        
        row = row-row%3;
        col = col-col%3;
        
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(grid[row+i][col+j] == num + '0')
                    return false;
            }
        }
        
        return true;
    }
    
    bool Temp(vector<vector<char>>& grid, int row, int col) {
        //cout<<"Hello"<<endl;
        if(row == N-1 && col == N) {
            return true;
        }
            
        if(col == N) {
            row++;
            col = 0;
        }
        
        if(grid[row][col] > '0')
            return Temp(grid, row, col+1);
            
        for(int i=1; i<=N; i++) {
            if(isValid(grid, row, col, i)) {
                grid[row][col] = i + '0';
                if(Temp(grid, row, col+1))
                    return true;
            }
            grid[row][col] = 0 + '0';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.')
                    board[i][j] = '0';
            }
        }
        auto a = Temp(board, 0, 0);
    }
};