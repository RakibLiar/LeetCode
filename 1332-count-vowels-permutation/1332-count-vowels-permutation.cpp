class Solution {
public:
    map<char, string> charList{
        {'a', "e"},
        {'e', "ai"},
        {'i', "aeou"},
        {'o', "iu"},
        {'u', "a"}
    };
    int MOD = 1000000007;
    int helper(vector<vector<int>> &dp, char cur, int pos, int n) {
        if(pos == n) return 1;
        if(dp[cur-'a'][pos] != -1) return dp[cur-'a'][pos];
        string s = charList[cur];
        int ans = 0;
        for(char c: s) {
            ans += helper(dp, c, pos+1, n);
            ans %= MOD;
        }
        return dp[cur-'a'][pos] = ans % MOD;
    }

    int countVowelPermutation(int n) {
        int ans = 0;
        string s = "aeiou";
        vector<vector<int>> dp(26, vector<int>(n, -1));
        for(char c: s) {
            ans += helper(dp, c, 1, n);
            ans %= MOD;
        }
        return ans % MOD;
    }
};