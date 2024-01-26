class Solution {
public:
    int MOD = 1000000007;
    bool check(int r, int c, int row, int col) {
        return 0 <= r && r < row && 0 <= c && c < col;
    }
    
    int calculate(int r, int c, int m, int maxMove, int row, int col, vector<vector<vector<int>>> &dp) {
        if(!check(r, c, row, col)) {
            return 1;
        }
        if( m <= 0) return 0;
        if(dp[r][c][m] != -1) return dp[r][c][m];
        vector<int> dir = {1 , 0, -1, 0, 1};
        int res = 0;
        for(int i=0; i<4; i++) {
            res += calculate(r+dir[i], c+dir[i+1], m-1, maxMove, row, col, dp);
            res %= MOD;
        }
        return dp[r][c][m] = res % MOD;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return calculate(startRow, startColumn, maxMove, maxMove, m, n, dp);
    }
};