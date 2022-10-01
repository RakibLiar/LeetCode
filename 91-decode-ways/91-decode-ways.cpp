class Solution {
public:
    int calculate(string s, string cur, int pos, vector<int> &dp) {
        if(cur.size() && (cur[0] == '0' || stoi(cur) > 26)) return 0;
        if(pos >= s.size()) return 1;
        if(dp[pos] != -1) return dp[pos];
        cur = "";
        if(pos + 2 <= s.size()) {
            dp[pos] = calculate(s, cur + s[pos], pos+1, dp) + calculate(s, cur + s[pos] + s[pos+1], pos+2, dp);
        } else {
            dp[pos] = calculate(s, cur + s[pos], pos+1, dp);
        }
        return dp[pos];
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return calculate(s, "", 0, dp);
    }
};