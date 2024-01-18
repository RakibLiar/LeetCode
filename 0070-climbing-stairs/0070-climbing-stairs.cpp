class Solution {
public:
    vector<int> dp;
    int hululu(int n) {
        if(n<=2) {
            return n;
        }
        if(dp[n] != -1) return dp[n];
        return dp[n] = hululu(n-1) + hululu(n-2);
    }
    int climbStairs(int n) {
        dp = vector<int>(n+1, -1);
        return hululu(n);
    }
};