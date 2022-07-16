class Solution {
public:
    vector<vector<vector<int>>> dp;
    int MOD = 1000000007, row, col;
    int check(int x, int y) {
        return 0<=x and x<row and 0<=y and y<col;
    }
    int calculate(int x, int y, int move) {
        if(!check(x, y)) {
           return 1; 
        }
        if(move <= 0) return 0;
        if(dp[x][y][move] != -1) return dp[x][y][move];
        vector<int> dir {1,0,-1,0,1};
        int a = 0;
        for(int i=0; i<dir.size()-1; i++) {
            int dx = x+dir[i];
            int dy = y+dir[i+1];
            a = (a+calculate(dx, dy, move-1))%MOD;
        }
        return dp[x][y][move] = a%MOD;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp = vector<vector<vector<int>>>(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1, -1)));
        row = m, col = n;
        return calculate(startRow, startColumn, maxMove);
    }
};