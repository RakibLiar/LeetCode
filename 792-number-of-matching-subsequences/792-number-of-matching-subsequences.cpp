class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> cnt(26);
        for(int i=0; i<s.size(); i++) {
            cnt[s[i]-'a'].push_back(i);
        }
        int res = 0;
        for(auto word: words) {
            int prev = -1, flag = 1;
            for(auto c: word) {
                auto upper = upper_bound(cnt[c-'a'].begin(), cnt[c-'a'].end(), prev);
                if(upper == cnt[c-'a'].end()) {
                    flag = 0;
                    break;
                }
                prev = upper - cnt[c-'a'].begin();
                prev = cnt[c-'a'][prev];
            }
            res += flag;
        }
        return res;
    }
};