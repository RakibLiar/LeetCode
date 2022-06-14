class Solution {
public:
    int calculate(string word1, string word2, vector<vector<int>> &dp, int pos1, int pos2) {
        if(pos1 == 0) return pos2;
        if(pos2 == 0) return pos1;
        
        if(dp[pos1][pos2] != -1) return dp[pos1][pos2];
        
        if(word1[pos1-1] == word2[pos2-1])
            return dp[pos1][pos2] = calculate(word1, word2, dp, pos1-1, pos2-1);
        
        return dp[pos1][pos2] = 1 + min(calculate(word1, word2, dp, pos1-1, pos2), min(calculate(word1, word2, dp, pos1, pos2-1), calculate(word1, word2, dp, pos1-1, pos2-1)));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));
        return calculate(word1, word2, dp, word1.size(), word2.size());
    }
};