class Solution {
public:
    vector<vector<int>> dp;
    Solution() {
        dp = vector<vector<int>>(1001, vector<int>(1001, -1));
    }
    int combinationSum4(vector<int>& nums, int sum, int pos = 0) {
        if(sum < 0) return 0;
        if(sum == 0) return 1;
        if(dp[pos][sum] != -1) return dp[pos][sum];
        int a = 0;
        for(int i=0; i<nums.size(); i++) {
            a += combinationSum4(nums, sum-nums[i], i);
        }
        return dp[pos][sum] = a;
    }
};