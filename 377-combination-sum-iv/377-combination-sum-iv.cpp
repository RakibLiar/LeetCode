class Solution {
public:
    vector<vector<int>> dp;
    int calculate(vector<int> &nums, int pos, int sum) {
        if(sum < 0) return 0;
        if(sum == 0) return 1;
        if(dp[pos][sum] != -1) return dp[pos][sum];
        int a = 0;
        for(int i=0; i<nums.size(); i++) {
            a += calculate(nums, i, sum-nums[i]);
        }
        return dp[pos][sum] = a;
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp = vector<vector<int>>(nums.size(), vector<int>(target+1, -1));
        return calculate(nums, 0, target);
    }
};