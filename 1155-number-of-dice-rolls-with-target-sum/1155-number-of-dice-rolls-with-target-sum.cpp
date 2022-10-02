class Solution {
public:
    int MOD = 1000000007;
    
    int calculate(vector<vector<int>> &dp, int k, int tar, int n, int ind, int sum) {
        //cout<<ind<<" "<<sum<<" "<<endl;
        if(ind == n && sum == tar) return 1;
        if(ind >= n || sum >= tar) return 0;
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int a = 0;
        for(int i=1; i<=k; i++) {
            a = (a + calculate(dp, k, tar, n, ind+1, sum+i))%MOD;
        }
        return dp[ind][sum] = a;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        //vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(target+1, vector<int>(k+1, -1)));
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return calculate(dp, k, target, n, 0, 0);
    }
};