class Solution {
public:
    int dp[601][101][101];
    int calculate(vector<pair<int, int>> &nums, int pos, int zero, int one) {
        if(pos >= nums.size() || zero<0 || one<0) return 0;
        if(dp[pos][zero][one] != -1) return dp[pos][zero][one];
        int res1 = INT_MIN, res2 = INT_MIN;
        if(zero >= nums[pos].first && one >= nums[pos].second) {
            res1 = calculate(nums, pos+1, zero-nums[pos].first, one-nums[pos].second) + 1;
        }
        res2 = calculate(nums, pos+1, zero, one);
        return dp[pos][zero][one] = max(res1, res2);
    }
    int findMaxForm(vector<string>& strs, int zero, int one) {
        vector<pair<int, int>> nums;
        memset(dp, -1, sizeof(dp));
        for(auto s: strs) {
            int countZero = count(s.begin(), s.end(), '0');
            nums.push_back({countZero, s.size()-countZero});
        }
        return calculate(nums, 0, zero, one);
    }
};