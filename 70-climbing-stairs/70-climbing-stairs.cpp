class Solution {
public:
    int calc(int n, vector<int> &dp) {
        if(n<1) return 0;
        if(dp[n] != -1) return dp[n];
        return dp[n] = calc(n-1, dp) + calc(n-2, dp);
    }
    
    int climbStairs(int n) {
        if(n<3) return n;
        vector<int> dp(n+1, -1);
        dp[1] = 1;
        dp[2] = 2;
        return calc(n, dp);
    }
};