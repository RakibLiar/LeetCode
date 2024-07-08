class Solution {
public:
    int MX = 100000;
    int calculateResult(vector<int> &nums, vector<int> &dp, int pos) {
        if(pos == nums.size() - 1) return 0;
        if(dp[pos] != MX) return dp[pos];
        
        for(int i=pos+1; i <= pos + nums[pos] && i < nums.size(); i++) {
            dp[pos] = min(dp[pos], 1 + calculateResult(nums, dp, i));
        }
        return dp[pos];
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), MX);
        return calculateResult(nums, dp, 0);
    }
};