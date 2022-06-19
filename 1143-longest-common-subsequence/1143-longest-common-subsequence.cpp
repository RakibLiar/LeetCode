class Solution {
public:
    vector<vector<int>> dp;
    int lcs(string text1, string text2, int pos1, int pos2) {
        if(pos1 == text1.size() || pos2 == text2.size()) return 0;
        if(dp[pos1][pos2] != -1) return dp[pos1][pos2];
        if(text1[pos1] == text2[pos2])
            return dp[pos1][pos2] = lcs(text1, text2, pos1+1, pos2+1) + 1;
        return dp[pos1][pos2] = max(lcs(text1, text2, pos1+1, pos2), lcs(text1, text2, pos1, pos2+1));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        dp = vector<vector<int>>(text1.size()+1, vector<int>(text2.size()+1, 0));
        for(int i=0; i<=text1.size(); i++) {
            for(int j=0; j<=text2.size(); j++) {
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};