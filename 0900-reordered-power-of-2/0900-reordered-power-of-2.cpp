class Solution {
public:
    bool reorderedPowerOf2(int a) {
        unordered_map<string, bool> mp;
        int n = 1;
        while(n <= 1e9) {
            string s = to_string(n);
            sort(s.begin(), s.end());
            mp[s] = true;
            n *= 2;
        }
        string s = to_string(a);
        sort(s.begin(), s.end());
        return mp.count(s) == 1;
    }
};