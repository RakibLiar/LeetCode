class Solution {
public:
    int calculate(vector<vector<int>> &dp, vector<int> &coins, int amount, int pos) {
        if(amount<0) return INT_MAX-100;
        if(amount == 0) {
            return 0;
        }
        if(pos >= coins.size()) {
            return INT_MAX-100;
        }
        if(dp[amount][pos] != -1) return dp[amount][pos];
        int ans1 = INT_MAX, ans2 = INT_MAX;
        if(amount>=coins[pos])
            ans1 = calculate(dp, coins, amount-coins[pos], pos) + 1;
        ans2 = calculate(dp, coins, amount, pos+1);
        return dp[amount][pos] = min(ans1, ans2);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(amount+1, vector<int> (coins.size(), -1));
        sort(coins.begin(), coins.end());
        int ans = calculate(dp, coins, amount, 0);
        return ans >= INT_MAX - 100 ? -1 : ans;
    }
};