class Solution {
public:
    int dp[15][10005], MAX = 1000000000;
    int coinChange(vector<int>& coins, int amount) {
        for(int i=0; i<15; i++) {
            for(int j=0; j<10005; j++)
                dp[i][j] = MAX;
            dp[i][0] = 0;
        }
        sort(coins.begin(), coins.end());
        for(int i=0; i<coins.size(); i++) {
            for(int j=1; j<=amount; j++) {
                if(j < coins[i])
                    dp[i+1][j] = dp[i][j];
                else
                    dp[i+1][j] = min(dp[i][j], dp[i+1][j-coins[i]]+1);
            }
        }
        return dp[coins.size()][amount] >= MAX ? -1 : dp[coins.size()][amount];
    }
};