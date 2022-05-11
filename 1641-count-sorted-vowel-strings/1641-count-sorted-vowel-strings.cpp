class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n][5];
        dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = 1;
        for(int i=1; i<n; i++) {
            for(int j=0; j<5; j++) {
                int a = 0;
                for(int k=j; k<5; k++) {
                    a += dp[i-1][k];
                }
                dp[i][j] = a;
            }
        }
        int ans = 0;
        for(int i=0; i<5; i++) {
            ans += dp[n-1][i];
        }
        return ans;
    }
};