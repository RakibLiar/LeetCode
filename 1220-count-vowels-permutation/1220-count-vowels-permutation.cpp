class Solution {
public:
    vector<vector<int>> dp, alpha{
        {1},
        {0,2},
        {0,1,3,4},
        {2,4},
        {0}
    };
    int MOD = 1000000007;
    
    int calculate(int pos, int al, int n) {
        if(pos >= n) return 1;
        if(dp[pos][al] != -1) return dp[pos][al];
        int ans = 0;
        for(int i=0; i<alpha[al].size(); i++) {
            ans += calculate(pos+1, alpha[al][i], n);
            ans %= MOD;
        }
        return dp[pos][al] = ans;
    }
    
    int countVowelPermutation(int n) {
        dp = vector<vector<int>>(n+1, vector<int>(5, -1));
        int ans = 0;
        for(int i=0; i<5; i++) {
            ans += calculate(1, i, n);
            ans %= MOD;
        }
        return ans;
    }
};