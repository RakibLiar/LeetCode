class Solution {
public:
    int calculate(vector<int> &nums, vector<int> &dp, int pos) {
        if(pos >= nums.size()) return 0;
        if(dp[pos] != -1) return dp[pos];
        return dp[pos] = max(calculate(nums, dp, pos+2) + nums[pos], calculate(nums, dp, pos+1));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return calculate(nums, dp, 0);
    }
};