class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() > b.size();
        });
        string ans;
        for(string s: words) {
            if(ans.find(s + "#") == string::npos) {
                ans += (s + "#");
            }
        }
        return ans.size();
    }
};