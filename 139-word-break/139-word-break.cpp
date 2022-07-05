class Solution {
public:
    unordered_map<string, string> mp;
    bool result = false;
    int dp[1005];
    int wordResult(string s, int pos) {
        //cout<<tempString<<" "<<pos<<endl;
        if(s.size() == pos) {
            return 1;
        }
        if(dp[pos] != -1) return dp[pos];
        string tempString = "";
        int a = 0;
        for(int i = pos; i<s.size(); i++) {
            tempString += s[i];
            if(mp.count(tempString)) {
                a = a | wordResult(s, i+1);
            }
            //dp[pos] = dp[pos] | a;
        }
        return dp[pos] = a;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0; i<s.size()+2; i++)
            dp[i] = -1;
        for(auto it: wordDict) {
            mp[it] = it;
        }
        return wordResult(s, 0) == 1 ? true : false;
    }
};