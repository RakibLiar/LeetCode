class Solution {
public:
    int calculate(vector<vector<int>>& triangle, vector<vector<int>> &dp, int row, int col) {
        if(col>row || row >= triangle.size()) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = min(calculate(triangle, dp, row+1, col), calculate(triangle, dp, row+1, col+1)) + triangle[row][col];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
        return calculate(triangle, dp, 0, 0);
    }
};