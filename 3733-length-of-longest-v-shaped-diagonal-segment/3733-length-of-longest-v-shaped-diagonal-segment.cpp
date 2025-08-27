class Solution {
public:
    int directionArray[5][2] = {{1,1}, {1, -1}, {-1, -1}, {-1, 1}, {1, 1}};
    int row, col;
    int dfs(vector<vector<vector<vector<int>>>> &dp, vector<vector<int>> &grid, int x, int y, int dir, bool hasTurned, int target) {
        int dx = x + directionArray[dir][0];
        int dy = y + directionArray[dir][1];
        if(dx < 0 || dx >=row || dy < 0 || dy >= col || grid[dx][dy] != target)
            return 0;

        if(dp[x][y][dir][hasTurned] != -1) return dp[x][y][dir][hasTurned];

        int maxStep = dfs(dp, grid, dx, dy, dir, hasTurned, 2-target);
        if(hasTurned) {
            //cout<<x<<" "<<y<<" "<<dir<<" "<<target<<endl;
            //cout<<maxStep<<endl;
            int a = dfs(dp, grid, dx, dy, dir+1, false, 2-target);
            maxStep = max(maxStep, a);
            //cout<<a<<" "<<maxStep<<endl<<endl;
        }
        return dp[x][y][dir][hasTurned] = maxStep + 1;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        vector<vector<vector<vector<int>>>> dp(row, vector<vector<vector<int>>>(col, vector<vector<int>>(5, vector<int>(2, -1))));
        int res = 0;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] == 1) {
                    for(int k=0; k<4; k++) {
                        res = max(res, dfs(dp, grid, i, j, k, true, 2) + 1);
                    }
                }
            }
        }
        return res;
    }
};