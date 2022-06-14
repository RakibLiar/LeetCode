class Solution {
public:
    int calculate(string word1, string word2, vector<vector<int>> &dp, int pos1, int pos2) {
        if(pos1>=word1.size() || pos2>=word2.size())
            return 0;
        if(dp[pos1][pos2] != -1) return dp[pos1][pos2];
        int res1 = 0, res2 = 0;
        if(word1[pos1] == word2[pos2])
            res1 = calculate(word1, word2, dp, pos1+1, pos2+1) + 1;
        else
            res2 = max(calculate(word1, word2, dp, pos1+1, pos2), calculate(word1, word2, dp, pos1, pos2+1));
        return dp[pos1][pos2] = max(res1, res2);
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        int a = calculate(word1, word2, dp, 0, 0);
        return word1.size() + word2.size() - 2*a;
    }
};