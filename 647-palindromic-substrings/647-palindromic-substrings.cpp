class Solution {
public:
    bool dp[1005][1005];
    int countSubstrings(string s) {
        memset(dp, false, sizeof(dp));
        for(int i=0; i<s.size(); i++)
            dp[i][i] = true;
        int cnt = 0;
        for(int i=s.size()-1; i>=0; i--) {
            cnt++;
            for(int j=i+1; j<s.size(); j++) {
                if(s[i] == s[j] && (dp[i+1][j-1] || i+1 == j)) {
                    dp[i][j] = true;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};