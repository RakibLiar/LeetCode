class Solution {
public:
    bool canAdd(string s, string p) {
        vector<char> v1(200, 0), v2(200, 0);
        for(int i=0; i<s.size(); i++) {
            if(v1[s[i]] == 0 && v2[p[i]] == 0) {
                v1[s[i]] = p[i];
                v2[p[i]] = s[i];
            } else if(v1[s[i]] == 0) {
                return false;
            } else if(v2[p[i]] == 0) {
                return false;
            } else {
                if(v1[s[i]] != p[i] || v2[p[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        vector<string> res;
        for(string s: words) {
            if(canAdd(s, p)) {
                res.push_back(s);
            }
        }
        return res;
    }
};