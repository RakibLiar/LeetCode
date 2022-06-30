class Solution {
public:
    vector<vector<int>> dp;
    int calculate(int isFirst, int prev, int pos, vector<int> &nums) {
        if(isFirst <= pos)
            return 0;
        /*if(pos == nums.size()-1) {
            if(isFirst) return 0;
            if(prev)
                return dp[prev][pos] = calculate(isFirst, false, pos+1, nums);
            return dp[prev][pos] = max(calculate(isFirst, true, pos+1, nums) + nums[pos], calculate(isFirst, false, pos+1, nums));
        }*/
        if(dp[prev][pos] != -1) return dp[prev][pos];
        if(prev)
            dp[prev][pos] = calculate(isFirst, false, pos+1, nums);
        else
            dp[prev][pos] = max(calculate(isFirst, true, pos+1, nums) + nums[pos], calculate(isFirst, false, pos+1, nums));
        return dp[prev][pos];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        dp = vector<vector<int>> (2, vector<int>(nums.size(), -1));
        int a = calculate(nums.size(), 0, 1, nums);
        dp = vector<vector<int>> (2, vector<int>(nums.size(), -1));
        int b = calculate(nums.size()-1, 1, 1, nums) + nums[0];
        return max(a, b);
    }
};