class Solution {
public:
    bool check(int c, int col) {
        return 0 <= c && c < col;
    }
    int calculate(vector<vector<vector<int>>> &dp, vector<vector<int>> &grid, int row, int col1, int col2) {
        if(row == grid.size()) return 0;
        if(col1 == col2) return 0;
        if(!check(col1, grid[0].size()) || !check(col2, grid[0].size())) return 0;
        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];
        
        vector<int> dir = {-1, 0, 1};
        int ans = 0;
        for(int d1: dir) {
            for(int d2: dir) {
                ans = max(ans, grid[row][col1] + grid[row][col2] + calculate(dp, grid, row+1, col1 + d1, col2 + d2));
            }
        }
        
        return dp[row][col1][col2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return calculate(dp, grid, 0, 0, grid[0].size()-1);
    }
};