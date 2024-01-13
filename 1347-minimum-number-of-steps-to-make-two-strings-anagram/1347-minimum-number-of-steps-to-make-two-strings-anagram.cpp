class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> v(26, 0);
        int cnt = 0;
        for(int i=0; i<s.size(); i++) {
            v[s[i]-'a']++;
            v[t[i]-'a']--;
        }
        for(int a: v) {
            cnt += max(0, a);
        }
        return cnt;
    }
};