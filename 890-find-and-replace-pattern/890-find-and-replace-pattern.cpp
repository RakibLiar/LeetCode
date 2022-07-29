class Solution {
public:
    void precalculate(vector<int> &vec, string &s) {
        int seq = 0;
        vector<int> v;
        for(char c: s) {
            if(vec[c-'a'] == -1) {
                vec[c-'a'] = seq++;
            }
        }
        for(int a: vec) {
            if(a != -1)
                v.push_back(a);
        }
        vec = v;
    }
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
        vector<int> pat(26, -1);
        vector<string> res;
        vector<char> vc(200, 0);
        precalculate(pat, p);
        for(string s: words) {
            if(canAdd(s, p)) {
                res.push_back(s);
            }
        }
        return res;
    }
};