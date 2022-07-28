class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<char> v1(256, 0), v2(256, 0);
        for(int i=0; i<s.size(); i++) {
            v1[s[i]]++;
            v2[t[i]]++;
        }
        return v1 == v2;
    }
};