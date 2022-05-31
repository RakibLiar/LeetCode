class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<int, bool> mp;
        for(int i=s.size()-k; i>=0; i--) {
            int n = 0;
            for(int j=i; j<i+k; j++) {
                n = 2*n + (s[j]-'0');
            }
            mp[n] = true;
        }
        return mp.size() == (1<<k);
    }
};