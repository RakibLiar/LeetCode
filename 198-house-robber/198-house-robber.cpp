class Solution {
public:
    int calculate(vector<int> &nums, vector<vector<int>> &dp, int prev, int pos) {
        if(pos == nums.size()) return 0;
        if(dp[prev][pos] != -1) return dp[prev][pos];
        if(prev == 1) {
            return dp[prev][pos] = calculate(nums, dp, 0, pos+1);
        }
        return dp[prev][pos] = max(calculate(nums, dp, 1, pos+1) + nums[pos], calculate(nums, dp, 0, pos+1));
    }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(nums.size(), -1));
        return max(calculate(nums, dp, 0, 0), calculate(nums, dp, 1, 0));
    }
};