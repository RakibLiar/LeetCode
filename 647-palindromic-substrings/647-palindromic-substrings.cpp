class Solution {
public:
    bool calculate(vector<vector<bool>> &dp, string s, int pos1, int pos2) {
        if(pos1>=pos2) return true;
        if(dp[pos1][pos2]) return true;
        if(s[pos1] != s[pos2])
            return dp[pos1][pos2] = false;
        return dp[pos1][pos2] = calculate(dp, s, pos1+1, pos2-1);
    }
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int cnt = 0;
        for(int i=0; i<s.size(); i++) {
            for(int j=i; j<s.size(); j++) {
                if(dp[i][j] || calculate(dp, s, i, j)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};