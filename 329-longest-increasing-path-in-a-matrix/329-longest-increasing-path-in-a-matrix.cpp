class Solution {
public:
    int dfs(vector<vector<int>> &dp, vector<vector<int>> &matrix, int x, int y, int prev) {
        if(x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size() || matrix[x][y] <= prev) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        int best = 0;
        vector<int> dir{0,1,0,-1,0};
        for(int i=0; i<dir.size()-1; i++) {
            int dx = x + dir[i];
            int dy = y + dir[i+1];
            best = max(best, dfs(dp, matrix, dx, dy, matrix[x][y]));
        }
        return dp[x][y] = best + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        int answer = INT_MIN;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                answer = max(answer, dfs(dp, matrix, i, j, INT_MIN));
            }
        }
        return answer;
    }
};