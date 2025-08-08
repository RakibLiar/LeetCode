class Solution {
public:
    double calculate(vector<vector<double>> &dp, int a, int b) {
        if (a<=0 && b>0) return 1;
        if (a<=0 && b<=0) return 0.5;
        if (a>0 && b<=0) return 0;
        if(dp[a][b] != -1) return dp[a][b];
        dp[a][b] =  0.25 * (calculate(dp, a-1, b-3) + calculate(dp, a-2, b-2) + calculate(dp, a-3, b-1) + calculate(dp, a-4, b));
        return dp[a][b];
    }

    double soupServings(int n) {
        if(n > 5000) return 1;
        n = ceil(n/25.0);
        vector<vector<double>> dp(n+1, vector<double>(n+1, -1));
        return calculate(dp, n, n);
    }
};