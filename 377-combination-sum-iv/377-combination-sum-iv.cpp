class Solution {
public:
    vector<unsigned int> dp;
    Solution() {
        dp = vector<unsigned int>(1001, 0);
    }
    int combinationSum4(vector<int>& nums, int sum, int pos = 0) {
        dp[0] = 1;
        for(int i=0; i<=sum; i++) {
            for(int x: nums) {
                if(i>=x) dp[i] += dp[i-x];
            }
        }
        return dp[sum];
    }
};