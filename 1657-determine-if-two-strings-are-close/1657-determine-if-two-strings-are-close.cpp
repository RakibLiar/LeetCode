class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> v1(26, 0), v2(26, 0);
        vector<bool> b(26, false);
        for(int c: word1) {
            v1[c-'a']++;
            b[c-'a'] = true;
        }
        for(int c: word2) {
            if(b[c-'a'] == false) return false;
            v2[c-'a']++;
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return v1 == v2;
    }
};