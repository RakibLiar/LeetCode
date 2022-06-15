class Solution {
public:
    vector<string> graph[18];
    unordered_map<string, int> word_map;
    vector<int> dp;
    int calculate(int pos, string word) {
        if(graph[word.size()-1].size() == 0) return word_map.count(word);
        if(dp[pos] != -1) return dp[pos];
        int cnt = 1;
        for(int j=0; j<word.size(); j++) {
            string s = word.substr(0, j) + word.substr(j+1);
            if(word_map.count(s)) {
                cnt = max(cnt, calculate(word_map[s], s) + 1);
            }
        }
        return dp[pos] = cnt;
    }
    
    int longestStrChain(vector<string>& words) {
        int len = words.size(), ans = 1;
        dp = vector<int> (len, -1);
        for(int i=0; i<len; i++) {
            string s = words[i];
            graph[s.size()].push_back(s);
            word_map[s] = i;
        }
        for(int i=0; i<len; i++) {
            if(dp[i] != -1)
                ans = max(ans, dp[i]);
            else
                dp[i] = calculate(i, words[i]);
        }
        for(int a: dp) {
            ans = max(ans, a);
        }
        return ans;
    }
};