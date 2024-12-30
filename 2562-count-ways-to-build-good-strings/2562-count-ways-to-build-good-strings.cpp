class Solution {
public:
    int MOD = 1000000007;
    int calculate(vector<int> &dp, int n, int zero, int one) {
        if(dp[n] != -1) return dp[n];
        int ans;
        if(n <= zero) ans = 1;
        if(n>=zero) ans += calculate(dp, n-zero, zero, one);
        if(n>=one) ans += calculate(dp, n-one, zero, one);
        return dp[n] = ans % MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, -1);
        return (calculate(dp, high, min(zero, one), max(zero, one)) - calculate(dp, low-1, min(zero, one), max(zero, one)) + MOD) % MOD;
    }
};