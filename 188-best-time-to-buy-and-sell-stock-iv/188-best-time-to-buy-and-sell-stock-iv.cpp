class Solution {
public:
    int resultDP(vector<vector<vector<int>>> &dp, vector<int> &nums, int k, int pos, int taken, int isEmpty) {
        if(taken > k || pos == nums.size()) return 0;
        if(dp[pos][taken][isEmpty] != -1) 
            return dp[pos][taken][isEmpty];
        if(isEmpty) {
            dp[pos][taken][isEmpty] = max(resultDP(dp, nums, k, pos+1, taken+1, 0) - nums[pos], resultDP(dp, nums, k, pos+1, taken, isEmpty));
        } else {
            dp[pos][taken][isEmpty] = max(resultDP(dp, nums, k, pos+1, taken, 1) + nums[pos], resultDP(dp, nums, k, pos+1, taken, isEmpty));
        }
        //cout<<pos<<" "<<taken<<" "<<isEmpty<<" "<<dp[pos][taken][isEmpty]<<endl;
        return dp[pos][taken][isEmpty];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() == 0) return 0;
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k+1, vector<int>(2, -1)));
        int res = max(resultDP(dp, prices, k, 0, 0, 1), resultDP(dp, prices, k, 1, 1, 0) - prices[0]);
        return res;
    }
};