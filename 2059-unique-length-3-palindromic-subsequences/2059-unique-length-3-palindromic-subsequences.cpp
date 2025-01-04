class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> right(26, 0), left(26, 0);
        for(auto c: s) {
            right[c-'a']++;
        }
        unordered_set<int> res;
        for(auto c: s) {
            int v = c-'a';
            right[v]--;
            for(int i=0; i<26; i++) {
                if(right[i] > 0 && left[i] > 0) {
                    res.insert(26*v + i);
                }
            }
            left[v]++;
        }
        return res.size();
    }
};