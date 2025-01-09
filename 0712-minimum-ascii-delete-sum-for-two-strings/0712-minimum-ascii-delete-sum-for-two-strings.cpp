class Solution {
public:
    int calculate(vector<vector<int>> &dp, int pos1, int pos2, string &s1, string &s2) {
        int a = 0;
        if(pos1 == s1.size()) {
            for(int i=pos2; i<s2.size(); i++) {
                a += s2[i];
            }
            return a;
        }
        if(pos2 == s2.size()) {
            for(int i=pos1; i<s1.size(); i++) {
                a += s1[i];
            }
            return a;
        }
        if(dp[pos1][pos2] != -1) return dp[pos1][pos2];
        if(s1[pos1] == s2[pos2]) {
            dp[pos1][pos2] = calculate(dp, pos1+1, pos2+1, s1, s2);
        } else {
            dp[pos1][pos2] = min(calculate(dp, pos1+1, pos2, s1, s2) + s1[pos1], calculate(dp, pos1, pos2+1, s1, s2) + s2[pos2]);
        }
        return dp[pos1][pos2];
    }

    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        return calculate(dp, 0, 0, s1, s2);
    }
};