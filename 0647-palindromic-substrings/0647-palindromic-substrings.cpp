class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for(int i=0; i<s.size(); i++) {
            dp[i][i] = true;
        }
        for(int i=s.size()-1; i>=0; i--) {
            for(int j=i+1; j<s.size(); j++) {
                if(s[i] == s[j]) {
                    if(i+1 <= j-1)
                        dp[i][j] = dp[i+1][j-1];
                    else
                        dp[i][j] = true;
                }
            }
        }
        int res = 0;
        for(int i=0; i<s.size(); i++) {
            for(int j=i; j<s.size(); j++) {
                if(dp[i][j]) res++;
            }
        }
        return res;
    }
};