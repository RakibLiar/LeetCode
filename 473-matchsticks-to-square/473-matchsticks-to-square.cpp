class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%4) return false;
        int tar = sum/4;
        int n = nums.size();
        vector<int> dp((1<<n)+2, -1);
        dp[0] = 0;
        for(int mask=0; mask<(1<<n); mask++) {
            if(dp[mask] == -1) continue;
            for(int j=0; j<n; j++) {
                if(!(mask&(1<<j)) && dp[mask]+nums[j]<=tar) {
                    dp[mask|(1<<j)] = (dp[mask]+nums[j])%tar;
                }
            }
        }
        return dp[(1<<n)-1] == 0;
    }
};